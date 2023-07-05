//
// Created by regino on 29/06/23.
//

#include <algorithm>
#include <iostream>
#include <utility>
#include "ToDoList.h"

ToDoList::ToDoList(std::string title) : title(std::move(title)) {

}

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
    this->displayToDos();
}

void ToDoList::removeTodo(std::string description) {
    ToDo deletedTodo = findTodo(std::move(description));
    toDoList.remove(deletedTodo);
    this->displayToDos();
}

void ToDoList::setTodoCompleted(std::string description) {
    ToDo setToDo = findTodo(description);
    if (!setToDo.isCompleted())
        setToDo.setCompleted(true);
}

void ToDoList::modifyTodo(std::string desc, std::string newDesc, bool completed) {
    ToDo modifyToDo = findTodo(desc);
    if (!newDesc.empty()) // se lascio newDesc vuota significa che voglio modificare solo il completed
        modifyToDo.setDescription(newDesc);

    modifyToDo.setCompleted(completed);
    this->displayToDos();
}



void ToDoList::displayToDos() {
    std::cout << "List of all todos:" << std::endl;
    for(auto & todo:toDoList) {
        std::cout << "-- " << todo.getDescription() << "\n";
        if (!todo.isCompleted())
            std::cout << "To be completed in " << todo.getDate() << "\n";
        else
            std::cout << " Already done!" << std::endl;
    }
}


void ToDoList::displayUncompletedToDos() {
    std::cout << "List of uncompleted todos:" << std::endl;
    for (auto &todo: toDoList) {
        if (!todo.isCompleted())
            std::cout << "-- " << todo.getDescription() << " - " << todo.getDate() << std::endl;
    }
}

const ToDo &ToDoList::findTodo(std::string desc) {
    static const ToDo emptyTodo; //forse non la soluzione migliore...

    // Scorro la lista tramite un iteratore
    for (auto &it: toDoList) {
        if (it.getDescription() == desc)
            return it;
    }
    //altrimenti ritorno un emptyTodo
    return emptyTodo;
}

