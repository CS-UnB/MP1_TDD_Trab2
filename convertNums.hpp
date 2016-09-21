/*
 * convertNums.hpp
 *
 *  Created on: Sep 19, 2016
 *      Author: otto
 */

#ifndef CONVERTNUMS_HPP_
#define CONVERTNUMS_HPP_
#include <string>
using std::string;

class ConvertNums {
  public:
    ConvertNums(){};
    int convert_toArabic(string& romanNumeral_String);
    int getRomanEquivalentValue(char  romanString);

  private:
    int VERIFY_ifFour(string & String_toVerify);
    int VERIFY_ifTwo(string & String_toVerify);
    int VERIFY_Subtraction(string & String_toVerify);
};

#endif /* CONVERTNUMS_HPP_ */
