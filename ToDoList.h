//
// Created by regino on 29/06/23.
//

#ifndef MYTODOLIST_TODOLIST_H
#define MYTODOLIST_TODOLIST_H

#include "ToDo.h"
#include <list>
#include <fstream>

class ToDoList {
public:
    explicit ToDoList(std::string title);

    ToDoList() = default;

    // Dei getters - setters controllare se utilizzati o no
    const std::list<ToDo> &getToDoList() const;

    void setToDoList(const std::list<ToDo> &toDoList);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void addToDo(const ToDo &todo);

    void removeTodo(const std::string &description);

    void removeTodos();

    void setTodoCompleted(const std::string &description);

    void modifyTodo(const std::string &desc, const std::string &newDesc, const Date &newDate);

    void displayAllToDos();

    void displayUncompletedToDos();

    ToDo &findTodo(const std::string &description);

    int getNumberOfTodos() const;

    int getNumberOfUncompletedTodos() const;

    //metodi per salvare e caricare file da disco
    void saveToFile(const std::string &fileName) const;

    static void loadFromFile(const std::string &fileName, ToDoList &newList);

private:
    ToDo &helperFindTodo(const std::string &description);

    std::list<ToDo> toDoList;
    std::string title;
    int numberOfTodos{0};
    int numberOfCompletedTodos{0};
};


#endif //MYTODOLIST_TODOLIST_H
