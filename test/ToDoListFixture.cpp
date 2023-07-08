//
// Created by regino on 08/07/23.
//
#include "gtest/gtest.h"
#include "../ToDoList.h"

class ToDoListFixture : public ::testing::Test {
protected:
    void SetUp() override {
        todolist.addToDo(ToDo(Date(8, 7, 2023), "Scrivere lo unit test delle classi"));
        todolist.addToDo(ToDo(Date(9, 7, 2023), "Scrivere mail al professore"));
    }

    void TearDown() override {
        todolist.removeTodos(); //questo metodo mi serve ogni volta a liberare le risorse per ogni test
    }

    ToDoList todolist{"My todolist"};
};

TEST_F(ToDoListFixture, RemoveTodoTest) {
    todolist.removeTodo("Scrivere lo unit test delle classi");
    EXPECT_EQ(todolist.getToDoList().size(), 1);

    //Testiamo quindi di togliere un todos non esistente
    testing::internal::CaptureStdout(); //mi serve per ottenere l'output del test
    todolist.removeTodo("Scrivere ciao al professore");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sorry there's not a todo with description: Scrivere ciao al professore\n");
}

TEST_F(ToDoListFixture, RemoveTodosTest) {
    todolist.removeTodos();
    ASSERT_EQ(todolist.getToDoList().size(), 0);
}

TEST_F(ToDoListFixture, SetTodoCompletedTest) {
    todolist.setTodoCompleted("Scrivere lo unit test delle classi");
    ASSERT_TRUE(todolist.getToDoList().front().isCompleted());
}

TEST_F(ToDoListFixture, ModifyTodoTest) {
    Date date;
    todolist.modifyTodo("Scrivere lo unit test delle classi",
                        "", Date(9, 7, 2023));
    EXPECT_EQ(todolist.getToDoList().front().getDate(), "9/7/2023");

    todolist.modifyTodo("Scrivere lo unit test delle classi",
                        "", date);
    EXPECT_EQ(todolist.getToDoList().front().isCompleted(), true);

    todolist.modifyTodo("Scrivere lo unit test delle classi",
                        "Scrivere lo unit test di todolist", date);
    EXPECT_EQ(todolist.getToDoList().front().getDescription(), "Scrivere lo unit test di todolist");
}

TEST_F(ToDoListFixture, DisplayUncompletedTodosTest) {
    todolist.setTodoCompleted("Scrivere lo unit test delle classi");

    testing::internal::CaptureStdout();
    todolist.displayUncompletedToDos();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "\nList of uncompleted todos:\n-- Scrivere mail al professore - 9/7/2023\n";
    ASSERT_EQ(output, expected);
}

TEST_F(ToDoListFixture, SaveAndLoadFromFileTest) {
    std::string fileName = "test_file.txt";
    todolist.saveToFile(fileName);

    ToDoList newList;
    ToDoList::loadFromFile(fileName, newList);

    EXPECT_EQ(newList.getTitle(), "My todolist");
    EXPECT_EQ(newList.getToDoList().size(), 2);
    EXPECT_EQ(newList.getToDoList().front().getDescription(), "Scrivere lo unit test delle classi");
    EXPECT_EQ(newList.getToDoList().front().getDate(), "8/7/2023");
    EXPECT_EQ(newList.getToDoList().back().getDescription(), "Scrivere mail al professore");
    EXPECT_EQ(newList.getToDoList().back().getDate(), "9/7/2023");

    std::remove(fileName.c_str()); //mi serve ad eliminare il file --> c_str() mi serve per accedere al percorso
}