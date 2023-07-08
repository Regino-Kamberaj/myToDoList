//
// Created by regino on 07/07/23.
//
#include "gtest/gtest.h"
#include "../ToDoList.h"

TEST(ToDoListTest, ConstructorTest) {
    ToDoList toDoList("My todolist");
    EXPECT_EQ(toDoList.getTitle(), "My todolist");
    EXPECT_TRUE(toDoList.getToDoList().empty());
}

TEST(ToDoListTest, AddTodoTest) {
    ToDoList toDoList("My todolist");
    toDoList.addToDo(ToDo(Date(10, 7, 2023), "Finire il lab di programmazione"));
    EXPECT_EQ(toDoList.getToDoList().size(), 1);
    EXPECT_EQ(toDoList.getToDoList().front().getDescription(), "Finire il lab di programmazione");
}