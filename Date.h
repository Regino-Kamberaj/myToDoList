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

    // Function to see if a year is leap
    static bool isLeap(const int &year);

    // Function to get the days of one month
    static int getDaysOfMonth(const int &month, const int &year);

    bool operator==(const Date &date) const;

private:
    // Function to see if a date is valid
    bool validDate(const int &day, const int &month, const int &year);

    bool validDay(const int &day) const;

    bool validMonth(const int &month);

    bool validYear(const int &year);


    int day;
    int month;
    int year;
};


#endif //MYTODOLIST_DATE_H
