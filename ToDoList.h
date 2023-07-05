//
// Created by regino on 29/06/23.
//

#ifndef MYTODOLIST_TODOLIST_H
#define MYTODOLIST_TODOLIST_H

#include "ToDo.h"
#include <list>

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

    void setTodoCompleted(std::string description);

    void modifyTodo(std::string desc, std::string newDesc, const Date &newDate);

    void displayToDos();

    void displayUncompletedToDos();

    void displayToDoList(); // todo da mettere??

private:
    ToDo &findTodo(std::string description);

    std::list<ToDo> toDoList;
    std::string title;

};


#endif //MYTODOLIST_TODOLIST_H
