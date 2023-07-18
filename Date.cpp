//
// Created by regino on 29/06/23.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int day, int month, int year) {
    if (!validDate(day, month, year))
        throw std::out_of_range("Date not valid!"); //controllare prima di assegnare
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    if (validDay(day, this->month, this->year))
        Date::day = day;
    else
        throw std::out_of_range("Day not valid!");

}

void Date::setMonth(int month) {
    if (validMonth(month)) {
        if (validDay(this->day, month,
                     this->year)) //controllo che effettivamente pure il giorno è valido per il nuovo mese
            Date::month = month;
        else
            throw std::out_of_range("Day not valid for the new month!");
    } else
        throw std::out_of_range("Month not valid!");

}

void Date::setYear(int year) {
    if (validYear(year)) {
        if (validDay(this->day, month,
                     this->year)) //controllo che effettivamente pure il giorno è valido per il nuovo mese
            Date::year = year;
        else
            throw std::out_of_range("Day not valid for the new year!");
    } else
        throw std::out_of_range("Year out of range!");
}

bool Date::isLeap(int year) const {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        } else
            return true;
    }
    return false;
}


int Date::getDaysOfMonth(int month, int year) const {
    switch (month) {
        case 2:
            // February
            if (isLeap(year))
                return 29;
            else
                return 28;
            break;
        case 4:
            // April
        case 6:
            // June
        case 9:
            // September
        case 11:
            // November
            return 30;
        default:
            // The other months have 31 days
            return 31;
    }
}


bool Date::validDate(int day, int month, int year) {
    if (validDay(day, month, year) && validMonth(month) && validYear(year))
        return true;
    else
        return false;
}

bool Date::operator==(const Date &date) const {
    if (this->day == date.day && this->month == date.month && this->year == date.year)
        return true;
    return false;
}

bool Date::validDay(int day, int month, int year) const {
    int maxDays = getDaysOfMonth(month, year);
    if (day > 0 && day <= maxDays)
        return true;
    return false;
}

bool Date::validMonth(int month) {
    if (month > 0 && month < 13)
        return true;
    return false;
}

bool Date::validYear(int year) {
    if (year >= 2000 && year <= 2100)
        return true;
    return false;
}



