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

void ToDoList::removeTodo(const std::string &description) {
    ToDo deletedTodo = findTodo(description);
    if (!deletedTodo.getDescription().empty()) {
        toDoList.remove(deletedTodo);
        this->displayToDos();
    } else
        std::cout << "Sorry there's not a todo with description: " << description << std::endl;
}

void ToDoList::setTodoCompleted(std::string description) {
    ToDo &setToDo = findTodo(description);
    if (!setToDo.isCompleted())
        setToDo.setCompleted();
}

void ToDoList::modifyTodo(std::string desc, std::string newDesc, const Date &newDate) {
    ToDo &modifyToDo = findTodo(desc);

    if (!modifyToDo.getDescription().empty()) {
        //per il momento posso modificare solo una cosa alla volta!
        if (!newDesc.empty()) // se lascio newDesc vuota significa che voglio modificare solo il completed
            modifyToDo.setDescription(newDesc);
        else if (!newDate.operator==(Date()))
            modifyToDo.setDate(newDate);
        else
            modifyToDo.setCompleted();

        this->displayToDos();
    } else
        std::cout << "Sorry there's not a todo with description: " << desc << std::endl;

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

ToDo &ToDoList::findTodo(std::string desc) {
    static ToDo emptyTodo; //forse non la soluzione migliore...

    // Scorro la lista tramite un iteratore
    for (auto &it: toDoList) {
        if (it.getDescription() == desc)
            return it;
    }
    //altrimenti ritorno un emptyTodo
    return emptyTodo;
}

