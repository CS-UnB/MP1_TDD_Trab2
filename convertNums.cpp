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


#define N 30


char romanNumeral[N];

int ConvertNums::getRomanEquivalentValue(char  romanString){	/*Converte numerais Romanos para Arabicos*/
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
		int sum = 0; char prev='%';
		for(int i=(romanNumeral_String.length()-1); i>=0; i--)
		{
			if(getRomanEquivalentValue(romanNumeral_String[i])<sum && (romanNumeral_String[i]!=prev))
			{       sum -= getRomanEquivalentValue(romanNumeral_String[i]);
			prev = romanNumeral_String[i];
			}
			else
			{
				sum += getRomanEquivalentValue(romanNumeral_String[i]);
				prev = romanNumeral_String[i];
			}
		}
		return sum;
	}


