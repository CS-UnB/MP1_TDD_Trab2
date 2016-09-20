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

	for(int i=(romanNumeral_String.length()-1); i>=0; i--){		 /*Avalia tamanho da String e percorre ela toda*/

		if(getRomanEquivalentValue(romanNumeral_String[i])<sum && (romanNumeral_String[i]!=prev)){
			sum -= getRomanEquivalentValue(romanNumeral_String[i]);
			prev = romanNumeral_String[i];
		}
		else{
			sum += getRomanEquivalentValue(romanNumeral_String[i]);
			prev = romanNumeral_String[i];
			if(VERIFY_ifFourI(romanNumeral_String) == -4) return -4;
		}

	}
	return sum;
}

int ConvertNums::VERIFY_ifFourI(string & String_toVerify){
	int i = 0;

	if(String_toVerify[(i)] == String_toVerify[i+1] &&
			String_toVerify[i+1] == String_toVerify[(i+2)] &&
			String_toVerify[(i+2)] == String_toVerify[(i+3)]){

		if(String_toVerify[i] == 'I') return -4;
		else if(String_toVerify[i] == 'X') return -4;
		else if(String_toVerify[i] == 'C') return -4;
		else if(String_toVerify[i] == 'M') return -4;
	}
		return 0;
}
