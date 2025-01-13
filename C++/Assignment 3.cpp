/*

This C++ program will calculate the average velocity 
of the person on the trampoline in small intervals 1 
second after they have launched off of the trampoline.

Name: Hengli Jia
Date: 10/16/2024

*/
#include<iostream>
#include<iomanip>
using namespace std;

int main(){

//Definition

    const double NUMGRAVITY=9.8;
    const double NUMINITIALSPEED=15.0;

    string operatorName;
    string subjectName;

    double numTime;
    double numTime1;
    double numTime2;
    double numTime3;
    
    double numHeight;
    double numHeight1;
    double numHeight2;
    double numHeight3;
    double avgVelocity1;
    double avgVelocity2;
    double avgVelocity3;


//Input

    cout << "Welcome, please enter the information below."<< endl;
    cout << "Enter the Opreator's name:";
    getline(cin,operatorName);
    cout << endl; 
    cout << "Enter the starting time in second:";
    cin >> numTime;
    cout << endl;

    cout << "Enter the first interval's end time:";
    cin >> numTime1;
    cout << "Enter the first interval's end time:";
    cin >> numTime2;
    cout << "Enter the first interval's end time:";
    cin >> numTime3;
    cout << endl;
    cin.get();
    
    cout << "Enter the test subject's name:";
    getline(cin,subjectName);
    cout << endl;

//Calculus

    //calculate the height of each position.
    numHeight = numTime * (NUMINITIALSPEED - 0.5 * NUMGRAVITY * numTime);
    numHeight1 = numTime1 * (NUMINITIALSPEED - 0.5 * NUMGRAVITY * numTime1);
    numHeight2 = numTime2 * (NUMINITIALSPEED - 0.5 * NUMGRAVITY * numTime2);
    numHeight3 = numTime3 * (NUMINITIALSPEED - 0.5 * NUMGRAVITY * numTime3);
    //calculate the average speed.
    avgVelocity1 = (numHeight1 - numHeight) / (numTime1 - numTime);
    avgVelocity2 = (numHeight2 - numHeight) / (numTime2 - numTime);
    avgVelocity3 = (numHeight3 - numHeight) / (numTime3 - numTime);



//Output

    cout << fixed << setprecision(3);
    cout << "Result:" << endl;
    cout << "height (m)   time interval (s)   avg.velocity (m/s)" << endl;

   
    cout << numHeight1 << setw(15) << numTime << " -> " 
    << numTime1 << setw(15) << avgVelocity1 << endl;

    cout << numHeight2 << setw(15) << numTime << " -> " 
    << numTime2 << setw(15) << avgVelocity2 << endl;

    cout << numHeight3 << setw(15) << numTime << " -> " 
    << numTime3 << setw(15) << avgVelocity3 << endl;

    cout << endl;

    cout << "Loggiong " << operatorName << " out of the system" << endl;
    cout << "Hope " << subjectName << " had a good trail" << endl;
    cout << "Have a nice day! " << endl;

    return 0;
}
/*
Welcome, please enter the information below.
Enter the Opreator's name:Genshin Impact

Enter the starting time in second:1

Enter the first interval's end time:1.1
Enter the first interval's end time:1.01
Enter the first interval's end time:1.001

Enter the test subject's name:Hengli Jia

Result:
height (m)   time interval (s)   avg.velocity (m/s)
10.571       1.000 -> 1.100       4.710
10.152       1.000 -> 1.010       5.151
10.105       1.000 -> 1.001       5.195

Loggiong Genshin Impact out of the system
Hope Hengli Jia had a good trail
Have a nice day!  

//My terminal is CMD, it doesn't give a run time.
*/