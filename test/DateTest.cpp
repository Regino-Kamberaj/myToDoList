//
// Created by regino on 07/07/23.
//
#include "gtest/gtest.h"
#include "../Date.h"

TEST(DateTest, ConstructorTest) {
    Date date(15, 9, 2000);
    EXPECT_EQ(date.getDay(), 15);
    EXPECT_EQ(date.getMonth(), 9);
    EXPECT_EQ(date.getYear(), 2000);
}

TEST(DateTest, DefaultConstructorTest) {
    Date date;
    EXPECT_EQ(date.getDay(), 0);
    EXPECT_EQ(date.getMonth(), 0);
    EXPECT_EQ(date.getYear(), 0);
}


TEST(DateTest, IsLeapTest) {
    //Prima eseguiamo dei test su diversi anni
    EXPECT_TRUE(Date::isLeap(2012));
    EXPECT_FALSE(Date::isLeap(2018));
    EXPECT_TRUE(Date::isLeap(2024));

    //Dunque testiamo una Data in generale
    Date date(15, 9, 2000);
    ASSERT_TRUE(date.isLeap(date.getYear()));
    date.setYear(2004);
    ASSERT_FALSE(date.isLeap(date.getYear()));
}

TEST(DateTest, GetDaysOfMonthTest) {
    //Stesso discorso qua
    EXPECT_EQ(Date::getDaysOfMonth(1, 2023), 31);
    EXPECT_EQ(Date::getDaysOfMonth(2, 2023), 28);
    EXPECT_EQ(Date::getDaysOfMonth(4, 2023), 30);

    Date date(15, 9, 2000);
    ASSERT_EQ(date.getDaysOfMonth(date.getMonth(), date.getYear()), 30);
    date.setMonth(2);
    ASSERT_EQ(date.getDaysOfMonth(date.getMonth(), date.getYear()), 29);
}

TEST(DateTest, EqualOperatorTest) {
    Date d1(10, 7, 2023);
    Date d2(10, 7, 2023);

    ASSERT_TRUE(d1 == d2);
    d2.setDay(11);
    ASSERT_FALSE(d1 == d2);
}

TEST(DateTest, InvalidDateTest) {
    EXPECT_THROW(Date date(29, 2, 2023), std::out_of_range);
    EXPECT_THROW(Date date(31, 4, 2023), std::out_of_range);
    EXPECT_THROW(Date date(33, 6, 2023), std::out_of_range);
    EXPECT_THROW(Date date(0, 7, 2023), std::out_of_range);
    EXPECT_THROW(Date date(10, 0, 2023), std::out_of_range);
    EXPECT_THROW(Date date(10, 13, 2023), std::out_of_range);
    EXPECT_THROW(Date date(10, 7, 1000), std::out_of_range);
    EXPECT_THROW(Date date(10, 7, 2200), std::out_of_range);
}

