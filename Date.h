//
// Created by regino on 29/06/23.
//

#ifndef MYTODOLIST_DATE_H
#define MYTODOLIST_DATE_H


class Date {
public:
    Date(int day, int month, int year);

    Date() : day(0), month(0), year(0) {}

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    bool operator==(const Date &date) const;

private:
    // Function to get the days of one month
    int getDaysOfMonth(int month, int year) const;

    // Function to see if a year is leap
    bool isLeap(int year) const;

    // Function to see if a date is valid
    bool validDate(int day, int month, int year);

    bool validDay(int day, int month, int year) const;

    bool validMonth(int month);

    bool validYear(int year);


    int day;
    int month;
    int year;
};


#endif //MYTODOLIST_DATE_H
