//
// Created by regino on 29/06/23.
//

#ifndef MYTODOLIST_TODOLIST_H
#define MYTODOLIST_TODOLIST_H

#include "ToDo.h"
#include <list>

class ToDoList {
public:
    explicit ToDoList(const std::string &title);

    // Dei getters - setters controllare se utilizzati o no
    const std::list<ToDo> &getToDoList() const;

    void setToDoList(const std::list<ToDo> &toDoList);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void addToDo(const ToDo& todo);

    void removeTodo(ToDo todo);
private:
    std::list<ToDo> toDoList;
    std::string title;
};


#endif //MYTODOLIST_TODOLIST_H
