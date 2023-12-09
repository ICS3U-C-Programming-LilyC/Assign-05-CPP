// Copyright (c) 2023 Lily Carroll All rights reserved.
//
// Created by: Lily Carroll
// Created on: Dec/8/2023
// This program gets 2 sides of a right
// angle triangle and calculates the hypotenuse.
// It uses a While True loop to run my program again.

// Using C++ libraries to get user input/output,
// calculate math and allow for use of std::.
#include <cmath>
#include <iomanip>
#include <iostream>

// Declaring function to calculate the hypotenuse.
float CalculateHypotenuse(float sideA, float sideB) {
    // Calculating hypotenuse.
    float sumOfSquares = (sideA * sideA) + (sideB * sideB);
    return std::sqrt(sumOfSquares);
}

// Declaring function to calculate the perimeter.
float CalculatePerimeter(float sideA, float sideB) {
    // Calling the calculated hypotenuse from
    // its function to use it for calculating
    // the perimeter.
    float hypotenuse = CalculateHypotenuse(sideA, sideB);
    // Calculating the perimeter.
    return sideA + sideB + hypotenuse;
}

// Declaring main() function to get user input/output,
// catch invalid inputs and loop.
int main() {
    // Explaining my program to the user.
    std::cout << "Welcome to my right triangle program in C++. ";
    std::cout << "My program will calculate the hypotenuse of any right";
    std::cout << "triangle using Pythagorean Theorem and can additionally ";
    std::cout << "calculate its perimeter. It uses a loop to allow";
    std::cout << " for my program to be run again.\n";

    // Declaring variables.
    int loopProgram = 0;
    std::string sideA;
    std::string sideB;
    std::string runProgramAgain;
    int runProgramAgainInt;
    float hypotenuse;
    float perimeter;

    // Initiating Do...While loop.
    do {
        // Getting user input for sides A and B.
        std::cout << "Enter the length of side A (cm): ";
        std::cin >> sideA;
        std::cout << "Enter the length of side B (cm): ";
        std::cin >> sideB;

        // Using a try-catch to catch any invalid
        // inputs for side lengths A and B.
        try {
            // Converting user inputs from strings
            // to floats.
            float sideAAsFloat = std::stof(sideA);
            float sideBAsFloat = std::stof(sideB);

            // Error checking for negative inputs for side lengths.
            if (sideAAsFloat <= 0 || sideBAsFloat <= 0) {
                    std::cout << "Side lengths must be greater than 0.";
                    break;
            }

            // Calling functions to display the
            // hypotenuse and perimeter.
            hypotenuse = CalculateHypotenuse(sideAAsFloat, sideBAsFloat);
            perimeter = CalculatePerimeter(sideAAsFloat, sideBAsFloat);

            // Rounding and printing the hypotenuse and
            // perimeter to the user.
            std::cout << "The hypotenuse is "
                      << std::fixed << std::setprecision(2)
                      << hypotenuse << " cm.\n";
            std::cout << "The perimeter is "
                      << std::fixed << std::setprecision(2)
                      << perimeter << " cm.\n";

            // Asking the user if they want to
            // run the program again.
            std::cout <<
            "Do you want to run the program again? (1 - Yes or 2 - No): ";
            std::cin >> runProgramAgain;

            // Using a try-catch to catch any invalid
            // inputs for user input regarding
            // if they would like to run my program again.
            try {
                // Converting user input from a string
                // to a float.
                runProgramAgainInt = std::stoi(runProgramAgain);

                // If statement to check if they did not
                // enter 1, meaning they do not want to
                // run my program again.

                if (runProgramAgainInt != 1) {
                    // If they did not enter 1 then break
                    // out of the loop.
                    break;
                }

                // Catching any errors for input
                // regarding if they want to run
                // my program again.
                    } catch (std::invalid_argument) {
                        std::cout <<
                        "Invalid input. Please enter 1 to run";
                        std::cout <<
                        " my program again or 2 to stop my program.\n";

                        // If the input is invalid then
                        // break out of the loop.
                        break;
                    }

                    // Assigning runProgramAgainInt variable to the
                    // value of loopProgram which holds the user's
                    // input (their decision to run my program again
                    // or not).
                    loopProgram = runProgramAgainInt;

            // Catching invalid inputs for side lengths.
            } catch (std::invalid_argument) {
            std::cout << "Invalid input for sides. Please try again.\n";
            // If the input for side lengths is invalid
            // then break out of the loop.
            break;
        }

        // While loop statement to run loop
        // only if the user's input (assigned
        // to the variable loopProgram)
        // is 1.
        } while (loopProgram == 1);
}
