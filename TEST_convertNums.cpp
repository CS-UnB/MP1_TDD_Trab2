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
  romanNumeral_toConvert = "XXIII";
  EXPECT_EQ(23, c.convert_toArabic(romanNumeral_toConvert));

  /*Casos de excecao*/
  /*Caso de quatro algorismos repetidos
   * I, X, C, M podem ser repetidos no maximo tres vezes*/
  romanNumeral_toConvert = "IIII";
  EXPECT_EQ(-4, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "XXXX";
  EXPECT_EQ(-4, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "CCCC";
  EXPECT_EQ(-4, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "MMMM";
  EXPECT_EQ(-4, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "IIMMMM";
  EXPECT_EQ(-4, c.convert_toArabic(romanNumeral_toConvert));

  /*Caso de dois algorismos repetidos
   * V, L, D nao podem ser repetidos*/
  romanNumeral_toConvert = "VV";
  EXPECT_EQ(-2, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "LL";
  EXPECT_EQ(-2, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "DD";
  EXPECT_EQ(-2, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "VDD";
  EXPECT_EQ(-2, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "LDDX";
  EXPECT_EQ(-2, c.convert_toArabic(romanNumeral_toConvert));

  /*Caso das subtracoes
   * I pode apenas ser subtraido de V e X
   * X pode apenas ser subtraido de L e C
   * C pode apenas ser subtraido de D e M
   * V, L e D nao podem ser subtraidos de nenhum outro algorismo*/
  romanNumeral_toConvert = "ILX";
  EXPECT_EQ(-1, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "XDM";
  EXPECT_EQ(-1, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "CXX";
  EXPECT_EQ(-1, c.convert_toArabic(romanNumeral_toConvert));	//CASO DEVE FALHAR
  romanNumeral_toConvert = "VXX";
  EXPECT_EQ(-1, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "LCC";
  EXPECT_EQ(-1, c.convert_toArabic(romanNumeral_toConvert));
  romanNumeral_toConvert = "DMM";
  EXPECT_EQ(-1, c.convert_toArabic(romanNumeral_toConvert));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
