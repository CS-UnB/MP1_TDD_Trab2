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
    ConvertNums() {}
    int getRomanEquivalentValue(char  romanString);
    int convert_toArabic(const string& romanNumeral_String);
};




#endif /* CONVERTNUMS_HPP_ */
