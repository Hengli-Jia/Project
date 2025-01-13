/*

This C++ program will figure out the minimum amount of graphene 
to produce for the company to break even or make at least
enough revenue to equal the costs from producing the graphene

Name: Hengli Jia
Date: 11/9/2024

*/


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function prototypes
void getStartingGuess(double &guess);
void calcRoots(double guess);
double calcProfits(double g);
double calcDerivative(double g);

// Main function
int main() {
    double numGuess;
    getStartingGuess(numGuess);
    calcRoots(numGuess);
    return 0;
}

// Function to prompt and validate a starting guess
void getStartingGuess(double &guess) {
    do {
        cout << "Enter a positive initial value: ";
        cin >> guess;
        if (guess <= 0) {
            cout << "Invalid input. Please enter a positive value." << endl;
        }
    } while (guess <= 0);

    cout << endl;
}

// Function to calculate and display roots using Newton's Method
void calcRoots(double guess) {
    const int iterations = 5;
    cout << fixed << setprecision(3);

    for (int i = 0; i < iterations; i++) {
        double profit = calcProfits(guess);
        double derivative = calcDerivative(guess);

        if (derivative == 0) {
            cout << "Derivative is zero. Newton's Method fails." << endl;
            return;
        }

        double newGuess = guess - profit / derivative;
        cout << "Iteration #" << (i + 1) << ": " << newGuess << endl;
        guess = newGuess;
    }

    cout << endl;
    cout << "Final approximation for number of grams to produce: ";
    cout << guess << "g" << endl;
}

// Function to calculate profits P(g)
double calcProfits(double g) {
    return -1000 + 2 * g - 3 * pow(g, 2.0 / 3.0) ;
}

// Function to calculate the derivative P'(g)
double calcDerivative(double g) {
    return 2 - 2 * pow(g, -1.0 / 3.0);
}
/*

Sample Run:

Enter a positive initial value: 1000000

Iteration #1: 5555.556
Iteration #2: 696.145
Iteration #3: 607.860
Iteration #4: 607.607
Iteration #5: 607.607

Final approximation for number of grams to produce: 607.607g

*/