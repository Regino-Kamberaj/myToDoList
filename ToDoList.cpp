//
// Created by regino on 29/06/23.
//

#include <algorithm>
#include <iostream>
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

void ToDoList::removeTodo(const ToDo& todo) {
    ToDo deletedTodo = findTodo(todo);
    toDoList.remove(deletedTodo);
    this->displayToDos();
}

void ToDoList::setTodoCompleted(const ToDo &todo) {
    ToDo setToDo = findTodo(todo);
    if (!setToDo.isCompleted())
        setToDo.setCompleted(true);
}

void ToDoList::modifyTodo(const ToDo &todo, std::string newDesc, bool completed) {
    ToDo modifyToDo = findTodo(todo);
    if (!newDesc.empty()) // se lascio newDesc vuota significa che voglio modificare solo il completed
        modifyToDo.setDescription(newDesc);

    modifyToDo.setCompleted(completed);
    this->displayToDos();
}



void ToDoList::displayToDos() {
    for(auto & todo:toDoList) {
        std::cout << '*) ' << todo.getDescription() << "\n";
        if (!todo.isCompleted())
            std::cout << "To be completed in " << todo.getDate() << "\n";
        else
            std::cout << " Already done!" << std::endl;
    }
}


void ToDoList::displayUncompletedToDos() {
    for(auto & todo:toDoList) {
        std::cout << "List of uncompleted todos:" << std::endl;
        if (!todo.isCompleted())
            std::cout << '*) ' << todo.getDescription() << " - " << todo.getDate() << std::endl;

}

const ToDo &ToDoList::findTodo(const ToDo &todo) {
    // Scorro la lista tramite un iteratore
    for (auto & it : toDoList) {
        if (it == todo) {
            return it;
        }
    }
}
