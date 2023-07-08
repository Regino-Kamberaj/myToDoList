//
// Created by regino on 07/07/23.
//
#include "gtest/gtest.h"
#include "../ToDo.h"

TEST(TodoTest, ConstructorTest) {
    ToDo todo(Date(15, 9, 2023), "Festeggia il compleanno");
    EXPECT_EQ(todo.getDate(), "15/9/2023");
    EXPECT_EQ(todo.getDescription(), "Festeggia il compleanno");
    EXPECT_FALSE(todo.isCompleted());
}

TEST(TodoTest, SetCompletedTest) {
    ToDo todo(Date(10, 7, 2023), "Finire il laboratorio di programmazione");
    todo.setCompleted();
    EXPECT_TRUE(todo.isCompleted());
    todo.setCompleted();
    EXPECT_FALSE(todo.isCompleted());
}

TEST(TodoTest, EqualityOperatorTest) {
    ToDo todo(Date(15, 9, 2023), "Festeggia il compleanno");
    ToDo todo2(Date(15, 9, 2023), "Festeggia il compleanno");
    ASSERT_TRUE(todo == todo2);
}

TEST(TodoTest, GetDateFromStringTest) {
    Date date = ToDo::getDateFromString("15/9/2000");
    EXPECT_EQ(date.getDay(), 15);
    EXPECT_EQ(date.getMonth(), 9);
    EXPECT_EQ(date.getYear(), 2000);

}