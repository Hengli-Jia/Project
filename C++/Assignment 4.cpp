/*

This C++ program will calculate the cost of
each Package, and give you the best guidance.

Name: Hengli Jia
Date: 10/22/2024

*/

#include <iostream>
#include <iomanip>
using namespace std;

// Definition
int numPackage;
int numMinutes;

double numPriceA;
double numPriceB;
double numPriceC;

const int COMBOA = 1;
const int COMBOB = 2;
const int COMBOC = 3;
const int NOCOMBO = 4;

const double NUMPRICEA = 39.99;
const double NUMPRICEB = 59.99;
const double NUMPRICEC = 69.99;

const double ADDA = 0.45;
const double ADDB = 0.40;

// Subfunciton
int calculateA(){

    cout << "The total amount due is $" << numPriceA << endl;

    if(numPriceA > numPriceB){
        cout << "Savings with Package B: $" << numPriceA - numPriceB << endl;
    }
    else{
        cout << "Savings with Package B: No Savings!" << endl;
    }

    if(numPriceA > numPriceC){
        cout << "Savings with Package C: $" << numPriceA - numPriceC << endl;
    }
    else{
        cout << "Savings with Package C: No Savings!" << endl;
    }
    return 0;
}
int calculateB(){

    cout << "The total amount due is $" << numPriceB << endl;

    if(numPriceB > numPriceA){
        cout << "Savings with Package A: $" << numPriceB - numPriceA << endl;
    }
    else{
        cout << "Savings with Package A: No Savings!" << endl;
    }

    if(numPriceB > numPriceC){
        cout << "Savings with Package C: $" << numPriceB - numPriceC << endl;
    }
    else{
        cout << "Savings with Package C: No Savings!" << endl;
    }
    return 0;
}
int calculateC(){

    cout << "The total amount due is $" << numPriceC << endl;

    if(numPriceC > numPriceA){
        cout << "Savings with Package A: $" << numPriceC - numPriceA << endl;
    }
    else{
        cout << "Savings with Package A: No Savings!" << endl;
    }

    if(numPriceC > numPriceB){
        cout << "Savings with Package B: $" << numPriceC - numPriceB << endl;
    }
    else{
        cout << "Savings with Package B: No Savings!" << endl;
    }
    return 0;
}

//Mainfunction
int main()
{
    

// Input
    cout << "Select a subscription package:" << endl;
    cout << "1. Package A" << endl;
    cout << "2. Package B" << endl;
    cout << "3. Package C" << endl;
    cout << "4. Quit" << endl;

    cin >> numPackage;

    cout << "How many minutes were used?" << endl;

    cin >> numMinutes;
// Initialize
    
    numPriceA = NUMPRICEA;
    numPriceB = NUMPRICEB;
    numPriceC = NUMPRICEC;

    cout << fixed << setprecision(2);

    if(numMinutes > 450){
         numPriceA = NUMPRICEA + (numMinutes - 450) * ADDA;
    }

    if(numMinutes > 900){
         numPriceB = NUMPRICEB + (numMinutes - 900) * ADDB;
    }

    
// Choose a package
    switch (numPackage){
    case COMBOA:
        calculateA();  break;
    case COMBOB:
        calculateB();  break;
    case COMBOC:
        calculateC();  break;
    case NOCOMBO:      break;
    default:           break;
    }
    
    return 0;
}
/* Sample Run

Select a subscription package:
1. Package A
2. Package B
3. Package C
4. Quit
1
How many minutes were used?
500
The total amount due is $62.49
Savings with Package B: $2.50
Savings with Package C: No Savings!

*/