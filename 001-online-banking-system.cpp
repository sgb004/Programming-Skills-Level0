/*
  Program: Online Banking System
  Autor: sgb004
  Date: 03/04/2024
  Description: This program is the solution to exercise number 1, read the level_0.txt file for more information.
  Compilation: This program needs password_hidden to be compiled first. If you use g++ you can use: g++ -o 001-online-banking-system password_hidden.cpp 001-online-banking-system.cpp
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "password_hidden.h"

using namespace std;

float balance = 2000;

float getAmount(string message){
	float amount;

	do{
		cout << message;
		cin >> amount;

		if(amount < 0){
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

void subtractFunds(float amount, string messageSuccess){
	float result = balance - amount;
	if(result >= 0){
		balance = result;
		cout << messageSuccess;
	}else{
		cout << "\nThere are insufficient funds to perform the operation.\n";
	}
}

string formatNumber(float number){
	char buffer[100];
    snprintf(buffer, sizeof(buffer), "%'.2f", number);
	string result = buffer;
	return "$" + result;
}

void deposit() {
	float amount = getAmount("\nHow much do you want to deposit?\n");
	bool confirm = confirmOperation("\nAre you sure you want to deposit " + formatNumber(amount) + " in your account?");

	if(confirm){
		balance = balance + amount;
		cout << "\nDeposit completed successfully.\n";
	}else{
		cout << "\nDeposit cancelled.\n";
	}
}

void withdraw() {
	float amount = getAmount("\nHow much do you want to withdraw?\n");
	bool confirm = confirmOperation("\nAre you sure you want to withdraw " + formatNumber(amount) + " from your account?");

	if(confirm){
		subtractFunds(amount, "\nWithdraw completed successfully.\n");
	}else{
		cout << "\nWithdraw cancelled.\n";
	}
}

void view() {
	cout << "\nYour current balance is " << formatNumber(balance) << " \n";
}

void transfer() {
	string person;
	float amount;
	bool confirm;

	cout << "\nTo whom do you wish to transfer?\n";
	getline(cin >> ws, person);

	amount = getAmount("\nHow much do you wish to transfer?\n");
	confirm = confirmOperation("\nAre you sure you want to transfer " + formatNumber(amount) + " to " + person + "?");

	if(confirm){
		subtractFunds(amount, "\nTransfer completed successfully.\n");
	}else{
		cout << "\nTransfer cancelled.\n";
	}
}

void menu() {
	int option;

	do {
		view();
		cout << "\nSelect the operation to perform:\n";
		cout << "1. Deposit\n";
		cout << "2. Withdraw\n";
		cout << "3. View\n";
		cout << "4. Transfer\n";
		cout << "0. Exit\n";
		cout << "\n";
		cin >> option;

		cout << "\n|--------------------------------------------------------------------|\n";

		switch (option) {
			case 1:
				deposit();
				break;
			case 2:
				withdraw();
				break;
			case 3:
				view();
				break;
			case 4:
				transfer();
				break;
			case 0:
				cout << "\nExiting the program.\n";
				break;
			default:
				cout << "\nInvalid option. Please try again.\n";
		}

		cout << "\n|--------------------------------------------------------------------|\n";
	} while (option != 0);
}

bool login(){
	bool login = false;

	string user = "admin";
	string password = "password";
	string userInput;
	string userPassword;

	char ch;

	for(int i = 0; i < 3; i++){
		cout << "Username: ";
		getline(cin, userInput);
		cout << "Password: ";
		userPassword = getHiddenPassword();

		if(user == userInput && password == userPassword){
			login = true;
			break;
		}else{
			cout << "\nIncorrect username or password.\n";
		}
	}

	return login;
}

int main() {
	setlocale(LC_NUMERIC, "en_US.UTF-8");

	cout << "\nWelcome to the online banking system.\n";

	if(login()){
		menu();
	}else{
		cout << "\nYour login credentials are incorrect.\n\n";
	}

	return 0;
}