//
// Created by regino on 29/06/23.
//

#ifndef MYTODOLIST_TODO_H
#define MYTODOLIST_TODO_H

#include "Date.h"
#include <string>
#include <utility>
#include <sstream>

class ToDo {
public:
    ToDo(const Date &date, const std::string &description, bool completed = false) : date(date),
                                                                                     description(description),
                                                                                     completed(completed) {
        // More code here...
    }


    std::string getDate() const {
        std::stringstream s;
        if (date.getDay() != 0)
            s << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
        return s.str();;
    }

    void setDate(const Date &date) {
        ToDo::date = date;
    }

    //funzione per ottenere un Date da una string, lo static è una forzatura ma necessaria
    static Date getDateFromString(const std::string &dateString) {
        std::istringstream iss(dateString);
        std::string token;
        int values[3];
        int i = 0;

        while (std::getline(iss, token, '/')) {
            values[i++] = std::stoi(token);
        }

        return Date(values[0], values[1], values[2]);
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

    void setCompleted() {
        if (!isCompleted())
            this->completed = true;
        else
            this->completed = false;
    }

    bool operator==(const ToDo &otherToDo) {
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
