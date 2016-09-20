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

int ConvertNums::convert_toArabic(string & romanNumeral_String){
	int sum = 0;
	char prev='%';

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
