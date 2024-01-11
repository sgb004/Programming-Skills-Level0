/*
  Header File: currency_conversions.h
  Author: sgb004
  Date: 10/01/2024
  Description: This file contains the declaration of the currency_conversions.cpp file.
*/

#include <iostream>
#include <map>

using namespace std;

void initListConversions();

map<string, float> getListConversions(string currency);

float getConversion(string currencyFrom, string currencyTo);