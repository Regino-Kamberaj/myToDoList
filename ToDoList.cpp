//
// Created by regino on 29/06/23.
//

#include <algorithm>
#include "ToDoList.h"

ToDoList::ToDoList(const std::string &title) : title(title) {}

const std::list<ToDo> &ToDoList::getToDoList() const {
    return toDoList;
}

void ToDoList::setToDoList(const std::list<ToDo> &toDoList) {
    ToDoList::toDoList = toDoList;
}

const std::string &ToDoList::getTitle() const {
    return title;
}

void ToDoList::setTitle(const std::string &title) {
    ToDoList::title = title;
}

void ToDoList::addToDo(const ToDo& todo) {
    // Add it to the end of the todolist
    toDoList.push_back(todo);
}

void ToDoList::removeTodo(ToDo todo) {
    // Scorro la lista tramite un iteratore
    for (auto it = toDoList.begin(); it != toDoList.end() ; ++it) {
        if (*it == todo) {
            toDoList.erase(it);
            break;
        }
    }

}


