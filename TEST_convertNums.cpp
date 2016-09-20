///*
// * TEST_compareNums.cpp
// *
// *  Created on: Sep 19, 2016
// *      Author: otto
// */
#include "convertNums.hpp"
#include <iostream>
using namespace std;
#include "gtest/gtest.h"





TEST(ConvertNums, GetRomanValue) {
	ConvertNums classObject;

	EXPECT_EQ(1, classObject.getRomanEquivalentValue('I'));
	EXPECT_EQ(5, classObject.getRomanEquivalentValue('V'));
	EXPECT_EQ(10, classObject.getRomanEquivalentValue('X'));
	EXPECT_EQ(100, classObject.getRomanEquivalentValue('C'));
	EXPECT_EQ(1000, classObject.getRomanEquivalentValue('M'));
}


TEST(ConvertNums, convert_toArabic) {
  ConvertNums c;

  string romanNumeral_toConvert = "I";
  EXPECT_EQ(1, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "II";
  EXPECT_EQ(2, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "IV";
  EXPECT_EQ(4, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "VI";
  EXPECT_EQ(6, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "IX";
  EXPECT_EQ(9, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "XI";
  EXPECT_EQ(11, c.convert_toArabic(romanNumeral_toConvert));

  romanNumeral_toConvert = "IIII";
  EXPECT_EQ(-4, c.convert_toArabic(romanNumeral_toConvert));	/*TESTE que deve falhar*/
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
