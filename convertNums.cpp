/*
 * convertNums.cpp
 *
 *  Created on: Sep 19, 2016
 *      Author: otto
 */
#include <iostream>
#include "convertNums.hpp"
#include <stdio.h>
#include <stdlib.h>


/*IMPLEMENTACAO*/
/**\p getRomanEquivalentValue
 * \brief Gets the int value to a char(Roman) character
 * \details Internal functions called within ConvertNums::covert_toArabic in a loop
 * which gets the value for each char member of a given RomanNumeral string
 * \param romanString Char of Roman numeral
 * \return returns int value equivalent to the Roman numeral char
 * */
int ConvertNums::getRomanEquivalentValue(char  romanString){
	switch(romanString){
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
	}
	return -1;
}

/**\p convert_toArabic
 * \brief Converts a given Roman string into an int value
 * \details Reads the string from back to front, calling the function getRomanEquivalentValue
 * and works with the data as follows:
 * if valueToLeft is smaller than the sumOfPrevious, subtracts the valueToLeft from the sum
 * else, adds the value to the sum
 * \param romanNumeral_String A given string of Roman numerals
 * \return Return the total sum of the integers for each char in the string, respecting sum rules
 * */
int ConvertNums::convert_toArabic(string & romanNumeral_String){
	int sum = 0;	/**< variable to control the sum of members*/
	char prev='%';	/**< saves value of the current position in the string before moving on the loop to the next value*/

	/*VERIFYING REQUISITES AND VALIDITY*/
	if(VERIFY_ifFour(romanNumeral_String) == -4) return -4;
	if(VERIFY_ifTwo(romanNumeral_String) == -2) return -2;
	/*VERIFYING if the subtraction is valid*/
	if(VERIFY_Subtraction(romanNumeral_String) == -1) return -1;

	for(int i=(romanNumeral_String.length()-1); i>=0; i--){		 /*Avalia tamanho da String e percorre ela toda*/

		if(getRomanEquivalentValue(romanNumeral_String[i])<sum && (romanNumeral_String[i]!=prev)){
			sum -= getRomanEquivalentValue(romanNumeral_String[i]);
			prev = romanNumeral_String[i];
		}
		else{
			sum += getRomanEquivalentValue(romanNumeral_String[i]);
			prev = romanNumeral_String[i];


		}

	}
	return sum;
}

/**\p VERIFY_ifFour
 * \brief Verify if there are four of same numeral in sequence
 * \details Given Roman numeral's formating rules, there can't be four of the same numeral in a sequence,
 * so this function verifies the string's validity
 * It is called with a loop, so verifies the numeral and its next 3
 * following numerals for each numeral itself until the end of the string
 * \param String_toVerify String passed to be verified
 * \return Returns -4 if there are 4 repeated members(invalid) and 0 if not(if valid)
 * */
int ConvertNums::VERIFY_ifFour(string & String_toVerify){
	for(int i=(String_toVerify.length()-1); i>=0; i--){
		if(String_toVerify[(i)] == String_toVerify[i+1] &&
				String_toVerify[i+1] == String_toVerify[(i+2)] &&
				String_toVerify[(i+2)] == String_toVerify[(i+3)]){

			if(String_toVerify[i] == 'I') return -4;
			else if(String_toVerify[i] == 'X') return -4;
			else if(String_toVerify[i] == 'C') return -4;
			else if(String_toVerify[i] == 'M') return -4;
		}
	}
	return 0;
}

/**\p VERIFY_ifTwo
 * \brief Verify if there are two of same numeral in sequence
 * \details Given Roman numeral's formating rules, there can't more than one of the given 'V', 'L' and 'D' numerals in sequence,
 * so this function verifies the string's validity
 * It is called with a loop, so verifies the numeral and its next
 * following numerals for each numeral itself until the end of the string
 * \param String_toVerify String passed to be verified
 * \return Returns -2 if there are 4 repeated members(invalid) and 0 if not(if valid)
 * */
int ConvertNums::VERIFY_ifTwo(string & String_toVerify){
	int stringLength = String_toVerify.length()-1;
	for(int i = 0; i <= stringLength; i++){
		if(String_toVerify[(i)] == String_toVerify[i+1]){

			if(String_toVerify[i] == 'V') return -2;
			else if(String_toVerify[i] == 'L') return -2;
			else if(String_toVerify[i] == 'D') return -2;
		}
	}
	return 0;
}

/**\p VERIFY_Subtraction
 * \brief Verify if RomanNumeral string follows formating rules
 * \details Function that verifies the validity of the string by following certain Roman numerals formation rules
 * such as:
 * - 'I' can only be subtracted(come before) from 'V' and 'X'
 * - 'X' can only be subtracted(come before) from 'L' and 'C'
 * - 'C' can only be subtracted(come before) from 'D' and 'M'
 * - 'V', 'L' and 'D' cannot be subtracted from any other numeral
 * It is called with a loop, so verifies the numeral and its following member to every memeber in the string
 *
 * \param String_toVerify String passed to be verified
 * \return Returns -1 if  formating is invalid and 0 if valid
 * */

int ConvertNums::VERIFY_Subtraction(string & String_toVerify){
	int stringLength = String_toVerify.length()-1;


	for(int i = 0; i <= stringLength; i++){
		if(getRomanEquivalentValue(String_toVerify[i]) < getRomanEquivalentValue(String_toVerify[(i + 1)])){
			switch(String_toVerify[i]){
			case 'I':
				if(String_toVerify[(i + 1)] == 'V' || String_toVerify[(i + 1)] == 'X')
					return 0;
				else return -1;

			case 'X':
				if(String_toVerify[(i + 1)] == 'L' || String_toVerify[(i + 1)] == 'C')
					return 0;
				else return -1;

			case 'C':
				if(String_toVerify[(i + 1)] == 'D' || String_toVerify[(i + 1)] == 'M')
					return 0;
				else return -1;

			case 'V':
				return -1;

			case 'L':
				return -1;

			case 'D':
				return -1;

			default:
				return 0;
			}
		}
		else return 0;
	}

	return 0;
}
