/*

This C++ program will calculate the ideal 
body weight for each person on the screen.

Name: Hengli Jia
Date: 11/6/2024

*/

#include<iostream>
#include<fstream>

using namespace std;

// To judge if heightInFeet is valid
bool judge(int heightInFeet){   
    if (heightInFeet < 5){
        return false;
    }
    else {
        return true;
    } 
}

// To calculate the ideal weight for each person
int calculate(int heightInFeet, int additionalInches){
    int idealWeight;
    idealWeight = 110 + ((heightInFeet - 5) * 12 + additionalInches  ) * 5;
    return idealWeight;
}

// Main function
int main(){
    // Definition
    ifstream inFile;
    string userName;
    int heightInFeet;
    int additionalInches;
    int idealWeight;

    // Openfile
    inFile.open("names-1.txt");

    if(inFile){
        while(getline(inFile, userName)){
            // Input
            inFile >> heightInFeet >> additionalInches;
            inFile.ignore();

            // Jump to judge function
            if(!judge(heightInFeet)){
                cout << "I can't calculate the ideal body weight for ";
                cout << userName << endl;
                continue;
            }
            // Jump to calculate function
            else{
                idealWeight = calculate(heightInFeet, additionalInches);
            }         

            // Output
            cout << "The ideal body weight for ";
            cout << userName;
            cout << " is " << idealWeight << " pounds." << endl;
        }
    }
    else{
        cout << "Error opening file." << endl;
    }

    // Closefile
    inFile.close();
    return 0;
}
/*

Sample Run:

    The ideal body weight for Tom Atto is 185 pounds.
    The ideal body weight for Eaton Wright is 135 pounds.
    The ideal body weight for Cary Oki is 165 pounds.
    I can't calculate the ideal body weight for Omar Ahmed

*/