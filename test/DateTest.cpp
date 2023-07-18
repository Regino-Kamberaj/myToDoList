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
    Date date(15, 9, 2000);
    date.setMonth(2);
    date.setDay(29);
    ASSERT_EQ(date.getDay(), 29);
    Date date2(15, 2, 2003);
    EXPECT_THROW(date2.setDay(29), std::out_of_range);
}

TEST(DateTest, GetDaysOfMonthTest) {
    Date date(15, 9, 2000);
    date.setDay(30);
    ASSERT_EQ(date.getDay(), 30);
    EXPECT_THROW(date.setMonth(2), std::out_of_range);
    date.setMonth(1);
    date.setDay(31);
    ASSERT_EQ(date.getDay(), 31);
    date.setYear(2003);
    date.setDay(28);
    date.setMonth(2);
    ASSERT_EQ(date.getDay(), 28);
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