/*
  Program: Online Banking System
  Autor: sgb004
  Date: 10/04/2024
  Description: This program is the solution to exercise number 2, read the level_0.txt file for more information.
  Compilation: This program needs currency_conversions and utils to be compiled first. If you use g++ you can use: g++ -o 002-currency-converter currency_conversions.cpp utils.cpp 002-currency-converter.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "currency_conversions.h"
#include "utils.h"


using namespace std;

struct Currency {
	string code;
	int min;
	int max;
};

vector<Currency> currencies = {
	{ "CLP", 1, 101 }, 
	{ "ARS", 2, 102 },
	{ "USD", 3, 103 },
	{ "EUR", 4, 104 }, 
	{ "TRY", 5, 105 }, 
	{ "GBP", 6, 106 }
};
Currency initialCurrency, exchangeToCurrency;

void printCurrenciesAllInfo(vector<Currency> currencies){
	map<string, float> conversions = getListConversions(initialCurrency.code);

	for(int i = 0; i < currencies.size(); i++ ){
		cout << i + 1 << ". " << currencies[i].code << ": " << formatNumberMoney(conversions[currencies[i].code]) << " | Min: " << formatNumberMoney(currencies[i].min)  << " | Max: " << formatNumberMoney(currencies[i].max) << "\n";
	}
}

void printCurrenciesCode(vector<Currency> currencies){
	for(int i = 0; i < currencies.size(); i++ ){
		cout << i + 1 << ". " << currencies[i].code << "\n";
	}
}

Currency selectCurrency(string title, string textReturn, vector<Currency> currencies, bool printAllInfo = true){
	int option;
	int currenciesSize = currencies.size();
	bool validOption = true;
	Currency currency;

	do{
		cout << title;
		if(printAllInfo){
		  printCurrenciesAllInfo(currencies);
		}else{
		  printCurrenciesCode(currencies);
		}
		cout << "0. " << textReturn << "\n";
		cin >> option;

		validOption = !(option >= 0 && option > currenciesSize);

		if(!validOption){
			cout << "\nInvalid option. Please try again.\n";
		}
	}while(!validOption);

	if(option > 0){
		currency = currencies[option - 1];
	}

	return currency;
}

vector<Currency> remainingCurrencies(){
	vector<Currency> remaining;
	
	for(const Currency& currency : currencies){
		if(currency.code != initialCurrency.code){
			remaining.push_back(currency);
		}
	}

	return remaining;
}

bool makeWithdraw(){
	bool result = confirmOperation("\nDo you want to withdraw your funds?");
	bool resultTransfer;

	if(result){
		string limit = "The amount have to minimum " + formatNumberMoney(exchangeToCurrency.min) + " and maximum " + formatNumberMoney(exchangeToCurrency.max);
		string label = "\nHow much do you want to withdraw? " + limit + "\n";
		bool validAmount = true;
		bool resultOperation;
		float amount, conversion, exchange, commission, total;

		do{
			amount = getAmount(label);

			validAmount = !(amount < exchangeToCurrency.min || amount > exchangeToCurrency.max);

			if(!validAmount){
				cout << "\nIncorrect amount, please correct it.\n";
			}
		}while(!validAmount);

		conversion = getConversion(initialCurrency.code, exchangeToCurrency.code);
		exchange = conversion * amount;
		commission = exchange / 100;
		total = exchange - commission;

		cout << "\n" << formatNumberMoney(amount) << " " << initialCurrency.code << " will be converted to " << formatNumberMoney(exchange) << " " << exchangeToCurrency.code << "\n";
		cout << "1\% of commission (" << formatNumberMoney(commission) << ")\n";
		cout << "total to withdraw: " << formatNumberMoney(total);
		resultOperation = confirmOperation("\nDo you want to withdraw your funds?");

		if(resultOperation){
			cout << "\nOperation completed successfully!\n";
		}else{
			cout << "\nOperation cancelled.\n";
		}
	}

	return result;
}

int main() {
	bool exit = true;

	setlocale(LC_NUMERIC, "en_US.UTF-8");

	initListConversions();

	cout << "\nWelcome to the currency converter system.\n";

	do{
		do{
			initialCurrency = selectCurrency("\nSelect an initial currency:\n", "Exit", currencies, false);

			if(initialCurrency.code != ""){
				exchangeToCurrency = selectCurrency("\nSelect the currency to exchange to:\n", "Change the initial currency", remainingCurrencies());
			}
		}while(initialCurrency.code != "" && exchangeToCurrency.code == "");

		if(initialCurrency.code != "" && exchangeToCurrency.code != ""){
			bool result = makeWithdraw();

			if(result){
				result = confirmOperation("\nDo you want to perform another operation?");
				exit = !result;
			}
		}
	}while(!exit);

	cout << "\nExiting the program.\n";
	
	return 0;
}