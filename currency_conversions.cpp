/*
  Program: currency_conversions.cpp
  Author: sgb004
  Date: 10/01/2024
  Description: This file contains functions that return the conversation values from one currency to another. The values are completely fictitious.
*/

#include <iostream>
#include <map>

using namespace std;

map<string, map<string, float>> conversionsList;

void initListConversions(){
	conversionsList["CLP"]["ARS"] = 1.11;
	conversionsList["CLP"]["USD"] = 2.11;
	conversionsList["CLP"]["EUR"] = 3.11;
	conversionsList["CLP"]["TRY"] = 4.11;
	conversionsList["CLP"]["GBP"] = 5.11;

	conversionsList["ARS"]["CLP"] = 1.12;
	conversionsList["ARS"]["USD"] = 2.12;
	conversionsList["ARS"]["EUR"] = 3.12;
	conversionsList["ARS"]["TRY"] = 4.12;
	conversionsList["ARS"]["GBP"] = 5.12;

	conversionsList["USD"]["CLP"] = 1.13;
	conversionsList["USD"]["ARS"] = 2.13;
	conversionsList["USD"]["EUR"] = 3.13;
	conversionsList["USD"]["TRY"] = 4.13;
	conversionsList["USD"]["GBP"] = 5.13;

	conversionsList["EUR"]["CLP"] = 1.14;
	conversionsList["EUR"]["ARS"] = 2.14;
	conversionsList["EUR"]["USD"] = 3.14;
	conversionsList["EUR"]["TRY"] = 4.14;
	conversionsList["EUR"]["GBP"] = 5.14;

	conversionsList["TRY"]["CLP"] = 1.15;
	conversionsList["TRY"]["ARS"] = 2.15;
	conversionsList["TRY"]["USD"] = 3.15;
	conversionsList["TRY"]["EUR"] = 4.15;
	conversionsList["TRY"]["GBP"] = 5.15;

	conversionsList["GBP"]["CLP"] = 1.16;
	conversionsList["GBP"]["ARS"] = 2.16;
	conversionsList["GBP"]["USD"] = 3.16;
	conversionsList["GBP"]["EUR"] = 4.16;
	conversionsList["GBP"]["TRY"] = 5.16;
}

map<string, float> getListConversions(string currency){
	return conversionsList[currency];
}

float getConversion(string currencyFrom, string currencyTo){
	return conversionsList[currencyFrom][currencyTo];
}