///*
// * TEST_compareNums.cpp
// *
// *  Created on: Sep 19, 2016
// *      Author: otto
// */
#include <iostream>
using namespace std;
#include "gtest/gtest.h"
#include "convertNums.hpp"




TEST(ConvertNums, getRomanEquivalentValue) {
	ConvertNums c;
	char value = 'I';
	EXPECT_EQ(1, c.getRomanEquivalentValue('I'));
	value = 'V';
	EXPECT_EQ(5, c.getRomanEquivalentValue(value));
	value = 'X';
	EXPECT_EQ(10, c.getRomanEquivalentValue(value));
	value = 'C';
	EXPECT_EQ(100, c.getRomanEquivalentValue(value));
	value = 'M';
	EXPECT_EQ(1000, c.getRomanEquivalentValue(value));
}


TEST(ConvertNums, convert_toArabic) {
  ConvertNums c;
  string valueToConvert= "I";
  EXPECT_EQ(1, c.convert_toArabic(valueToConvert));
  valueToConvert = "II";
  EXPECT_EQ(2, c.convert_toArabic(valueToConvert));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
