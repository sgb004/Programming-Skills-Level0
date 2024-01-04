/*
  Header File: password_hidden.h
  Author: ChatGTP
  Date: 03/04/2024
  Description: This file contains the declaration of the password_hidden class.
*/

#ifndef PASSWORD_HIDDEN_H
	#define PASSWORD_HIDDEN_H

	#include <string>

	// Function to disable echo in the terminal.
	void disableEcho();

	// Function to enable echo in the terminal.
	void enableEcho();

	// Function to get a hidden password.
	std::string getHiddenPassword();

#endif  // PASSWORD_HIDDEN_H
