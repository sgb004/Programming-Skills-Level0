/*
  Program: utils.cpp
  Author: sgb004
  Date: 10/01/2024
  Description: This file has functions that are uses in the exercises.
*/

#include <iostream>

using namespace std;

float getAmount(string message){
	float amount;

	do{
		cout << message;
		cin >> amount;

		if(amount <= 0){
			cout << "\nThe amount must be greater than zero.\n";
		}
	}while(amount <= 0);

	return amount;
}

bool confirmOperation(string message){
	char confirm;
	cout << message << " [write y to confirm or any character to cancel]\n";
	cin >> confirm;
	return (confirm == 'y' || confirm == 'Y');
}

string formatNumber(float number){
	char buffer[100];
	snprintf(buffer, sizeof(buffer), "%'.2f", number);
	return buffer;
}

string formatNumberMoney(float number){
	string result = formatNumber(number);
	return "$" + result;
}
