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
    //Dunque testiamo una Data in generale
    Date date(15, 9, 2000);
    ASSERT_TRUE(date.isLeap(date.getYear()));
    date.setYear(2003);
    ASSERT_FALSE(date.isLeap(date.getYear()));
}

TEST(DateTest, GetDaysOfMonthTest) {
    Date date(15, 9, 2000);
    ASSERT_EQ(date.getDaysOfMonth(date.getMonth(), date.getYear()), 30);
    date.setMonth(2);
    ASSERT_EQ(date.getDaysOfMonth(date.getMonth(), date.getYear()), 29);
}

TEST(DateTest, EqualityOperatorTest) {
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

TEST(DateTest, SettersDateTest) {
    Date date(10, 12, 2023);
    EXPECT_THROW(date.setDay(340), std::out_of_range);
    EXPECT_THROW(date.setMonth(0), std::out_of_range);
    EXPECT_THROW(date.setYear(30000), std::out_of_range);
    date.setDay(15);
    date.setMonth(9);
    date.setYear(2000);
    ASSERT_EQ(date, Date(15, 9, 2000));
}