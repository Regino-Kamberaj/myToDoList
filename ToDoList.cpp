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
    this->displayAllToDos();
}

void ToDoList::removeTodo(const std::string &description) {
    ToDo deletedTodo = findTodo(description);
    if (!deletedTodo.getDescription().empty()) {
        toDoList.remove(deletedTodo);
        this->displayAllToDos();
    } else
        std::cout << "Sorry there's not a todo with description: " << description << std::endl;
}

void ToDoList::setTodoCompleted(std::string description) {
    ToDo &setToDo = findTodo(std::move(description));
    if (!setToDo.isCompleted())
        setToDo.setCompleted();
    this->displayAllToDos();
}

void ToDoList::modifyTodo(const std::string &desc, const std::string &newDesc, const Date &newDate) {
    ToDo &modifyToDo = findTodo(desc);

    if (!modifyToDo.getDescription().empty()) {
        //per il momento posso modificare solo una cosa alla volta!
        if (!newDesc.empty()) // se lascio newDesc vuota significa che voglio modificare solo il completed
            modifyToDo.setDescription(newDesc);
        else if (!newDate.operator==(Date()))
            modifyToDo.setDate(newDate);
        else
            modifyToDo.setCompleted();

        this->displayAllToDos();
    } else
        std::cout << "Sorry there's not a todo with description: " << desc << std::endl;

}


void ToDoList::displayAllToDos() {
    std::cout << "\nList of all todos from " << this->title << ": " << std::endl;
    for (auto &todo: toDoList) {
        std::cout << "-- " << todo.getDescription() << " - ";
        if (!todo.isCompleted())
            std::cout << "To be completed in " << todo.getDate() << "\n";
        else
            std::cout << "Already done!" << std::endl;
    }
}


void ToDoList::displayUncompletedToDos() {
    std::cout << "\nList of uncompleted todos:" << std::endl;
    for (auto &todo: toDoList) {
        if (!todo.isCompleted())
            std::cout << "-- " << todo.getDescription() << " - " << todo.getDate() << std::endl;
    }
}

ToDo &ToDoList::findTodo(const std::string &desc) {
    static ToDo emptyTodo; //forse non la soluzione migliore...

    // Scorro la lista tramite un iteratore
    for (auto &it: toDoList) {
        if (it.getDescription() == desc)
            return it;
    }
    //altrimenti ritorno un emptyTodo
    return emptyTodo;
}

void ToDoList::saveToFile(const std::string &fileName) const {
    std::ofstream file(fileName);

    if (file.is_open()) {
        file << title << std::endl;
        for (const auto &todo: toDoList) {
            file << todo.getDescription() << "- " << todo.getDate() << " - ";
            if (todo.isCompleted())
                file << "completed." << std::endl;
            else
                file << "uncompleted." << std::endl;
        }
        file.close();
    } else
        throw (std::runtime_error) "File not saved";
}

void ToDoList::loadFromFile(const std::string &fileName, ToDoList &newList) {
    std::ifstream file(fileName);

    if (file.is_open()) {
        //prendi il titolo
        std::string line;
        std::getline(file, newList.title);
        //prendi i todo fino a quando finiscono
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string desc, dateString, completed;
            std::getline(ss, desc, '-');
            std::getline(ss, dateString, '-');
            std::getline(ss, completed, '.');
            bool isCompleted = (completed == "completed") ? true : false;
            Date dueDate = ToDo::getDateFromString(dateString);
            newList.toDoList.emplace_back(dueDate, desc, isCompleted);
        }
        file.close();
    } else
        throw (std::runtime_error) "File not found!";
}




