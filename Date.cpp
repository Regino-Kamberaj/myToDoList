//
// Created by regino on 29/06/23.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int day, int month, int year): day(day), month(month), year(year) {
    // More code here...
    if (!validDate(day, month, year))
        throw std::out_of_range("Data non valida!")
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

bool Date::isLeap(const int &year) {
    if(year % 4 == 0) {
        if(year % 100 == 0){
            if(year % 400 == 0)
                return true;
            else
                return false;
        } else
            return true;
    }
    return false;
}


int Date::getDaysOfMonth(const int &month, const int &year) {
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


bool Date::validDate(const int &day, const int &month, const int &year) {
    if(year >= 2023 && month > 0 && month < 13 && day > 0 && day <= getDaysOfMonth(month))
        return true;
    else
        return false;
}

bool Date::operator==(const Date &date) const {
    if (this->day == date.day && this->month == date.month && this->year == date.year)
        return true;
    return false;
}
