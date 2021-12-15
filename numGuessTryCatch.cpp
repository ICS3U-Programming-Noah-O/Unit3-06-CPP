// Copyright (c) 2021 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Dec. 9, 2021
// This program allows a user to guess a number between 0
// and 9 with a randomly generated number
#include <iostream>
#include <iomanip>
#include <random>


// declare constants
int CONST_NUM = 8;


int main() {
  // Generate random number
  int randomNumber;

  std::random_device rseed;

  std::mt19937 rgen(rseed());  // mersenne_twister

  std::uniform_int_distribution<int> idist(0, 9);

  randomNumber = idist(rgen);

  // get input from user
  std::string userString;
  int userNumber;
  std::cout << "I have picked a number between 0 and 9!\n";
  std::cout << "Guess my number!.\n";
  std::cout << " \n";
  std::cout << "Enter your guess: ";
  std::cin >> userString;

  // Make sure user number is valid and check if they
  // guessed correctly
  try {
    userNumber = std::stoi(userString);
    if (userNumber == randomNumber) {
      std::cout << "You guessed correctly!.\n";
     } else {
      std::cout << "Sorry that is incorrect. " << "The answer was ";
      std::cout << randomNumber << ". Try again!\n";
      std::cout << " \n";
        }
    } catch (std::invalid_argument) {
        std::cout << userString << " is not a valid integer\n";
    }
}
