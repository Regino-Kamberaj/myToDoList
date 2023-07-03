//
// Created by regino on 29/06/23.
//

#ifndef MYTODOLIST_TODO_H
#define MYTODOLIST_TODO_H

#include "Date.h"
#include <string>

class ToDo {
public:
    ToDo(const Date &date, const std::string &description) :date(date), description(description), completed(
            false) {
        // More code here...
    }

    const Date &getDate() const {
        return date;
    }

    void setDate(const Date &date) {
        ToDo::date = date;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        ToDo::description = description;
    }

    bool isCompleted() const {
        return completed;
    }

    void setCompleted(bool completed) {
        ToDo::completed = completed;
    }

    bool operator==(const ToDo& otherToDo) {
        if (this->date == otherToDo.date && this->description == otherToDo.description)
            return true;
        return false;
    }
private:
    Date date;
    std::string description;
    bool completed;
};
#endif //MYTODOLIST_TODO_H
