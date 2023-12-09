// Copyright (c) 2023 Lily Carroll All rights reserved.
//
// Created by: Lily Carroll
// Created on: Dec/1/2023
// This program gets 2 sides of a right
// angle triangle and calculates the hypotenuse.
// It uses a While True loop to run my program again.

// Using C++ libraries to get user input/output,
// calculate math and allow for use of std::.
#include<iostream>
#include<cmath>
#include<string>

// Declaring function to calculate the hypotenuse.
float CalculateHypotenuse(float sideA, float sideB) {
    // Declaring variables
    float sumOfSquares;
    float hypotenuse;
    // Calculating hypotenuse.
    sumOfSquares = (sideA * sideA) + (sideB * sideB);
    hypotenuse = std::sqrt(sumOfSquares);
    return hypotenuse;
}

// Declaring function to calculate the perimeter.
float CalculatePerimeter(float sideA, float sideB) {
    // Declaring variables.
    float perimeter;
    float hypotenuse;
    // Calling the calculated hypotenuse from its
    // function to use it for calculating the perimeter.
    hypotenuse = CalculateHypotenuse(sideA, sideB);
    // Calculating the perimeter.
    perimeter = sideA + sideB + hypotenuse;
    // Returning the perimeter to the function.
    return perimeter;
}

// Declaring main() function to get user
// input/output, catch invalid inputs and
// loop.
int main() {
    // Using a Do...While loop to allow for
    // main() function to be run more than
    // once, if the user would like to.
    do {
        // Explaining my program to the user.
        std::cout << "Welcome to my right triangle program in python.";
        std::cout << " My program will calculate the hypotenuse of any right";
        std::cout << " triangle using Pythagorean Theorem and can additionally";
        std::cout << " calculate its perimeter. It uses a loop to allow";
        std::cout << " for my program to be run again.";

        // Declaring variables.
        std::string sideA;
        std::string sideB;
        std::string userInputForLoop;
        float hypotenuse;
        float perimeter;

        // Getting user input for sides A and B.
        std::cout << "Enter the length of side A (cm): ";
        std::cin >> sideA;
        std::cout << "Enter the length of side B (cm): ";
        std::cin >> sideB;

        // Using a try catch to catch any invalid
        // inputs for side lengths A and B.
        try {
            float sideAAsFloat = std::stof(sideA);
            float sideBAsFloat = std::stof(sideB);

            // Calculating hypotenuse and perimeter.
            hypotenuse = CalculateHypotenuse(sideAAsFloat, sideBAsFloat);
            perimeter = CalculatePerimeter(sideAAsFloat, sideBAsFloat);

            // Displaying the hypotenuse and perimeter to the user.
            std::cout << "The hypotenuse is "<< std::fixed
            << std::setprecision(2) << hypotenuse << "\n";
            std::cout << "The perimeter is " << std::fixed
            << std::setprecision(2) << perimeter << "\n";

            // Asking the user if they want to run the program again.
            std::cout <<
            "Do you want to run the program again? (1 - Yes or 2 - No): ";
            std::cin >> userInputForLoop;

            // Using a try catch to catch any invalid
            // inputs for user input regarding if they
            // would like to run my program again.
            try {
                int userInputForLoopAsInt = std::stoi(userInputForLoop);

                // Using if statement to check if the
                // user's input is not equal to 1,
                // then break out of the loop.
                if (userInputForLoopAsInt != "1") {
                        break;
                    }
            // Catching invalid inputs regarding running my program again.
            } catch (std::invalid_argument) {
                std::cout <<
                "Invalid input. Please enter 1 to run my program again";
                std::cout << "or 2 to stop my program.";
                break;
            }
        // Catching invalid inputs for side lengths.
        } catch (std::invalid_argument) {
            std::cout <<
            "Invalid input for sides. Please try again.";
        }
    } while (userInputForLoopAsInt == "1");
}
