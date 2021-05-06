// Copyright (c) 2021 Luke Beausoleil All rights reserved
//
// Created by: Luke Beausoleil
// Created on: May 2021
// This program gets the user to guess a pseudo-random number

#include <iostream>
#include <random>
#include <string>

int main() {
    // this function generates a pseudo-random number and gets the user to
    //      guess it

    // variables
    std::string guessAsString;
    int correctNumber;
    int guessAsInteger;

    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);  // [0,9]
    correctNumber = idist(rgen);

    // input
    std::cout << "Guess a number from 0 - 9: ";
    std::cin >> guessAsString;

    // process & output
    try {
        guessAsInteger = std::stoi(guessAsString);
        if (guessAsInteger == correctNumber) {
            std::cout << "\nCorrect!" << std::endl;
        } else {
            std::cout << "\nIncorrect! The number was " <<
                  correctNumber << "." << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "\n" << guessAsString << " is not a valid input"
              << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
