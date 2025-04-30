/*

This C++ program will display the total number of correctly answered 
questions, the total number of incorrectly answered questions, and a 
list showing the question numbers of the incorrectly answered questions. 

Date: 11/20/2024

*/

#include <iostream>
using namespace std;

// Function prototypes
void input(char studentAnswers[], int size);
void checkAnswers(const char correctAnswers[], const char 
studentAnswers[], int &correct, int &incorrect, int size);

int main() {

    // Intialization
    const int SIZE = 20;
    int correct = 0, incorrect = 0;
    char correctAnswers[SIZE] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 
    'B', 'C', 'D','A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    char studentAnswers[SIZE];

    cout << "Please enter the student's answers for each of the questions." ;
    cout << endl;
    cout << "Press Enter after typing each answer." ;
    cout << endl;
    cout << "Please enter only an A, B, C, D or a, b, c, dfor each question.";
    cout << endl;

    // Get student's answers
    input(studentAnswers, SIZE);

    // Compare answers and calculate results
    checkAnswers(correctAnswers, studentAnswers, correct, incorrect, SIZE);

    // Display results
    cout << "Questions that were answered incorrectly:" << endl;
    for (int i = 0; i < SIZE; i++) {
        if (toupper(studentAnswers[i]) != correctAnswers[i]) {
            cout << i + 1 << endl;
        }
    }
    cout << endl;

    if (correct >= 15) {
        cout << endl << "The student passed the exam." << endl;
    } 
    else {
        cout << endl << "The student failed the exam." << endl;
    }

    cout << endl << "Correct Answers: " << correct;
    cout << endl << "Incorrect Answers: " << incorrect;
    cout << endl;

    return 0;
}

// Function to input student's answers with validation
void input(char studentAnswers[], int size) {
    for (int i = 0; i < size; i++) {
        char answer;
        bool valid = false;
        cout << "Question " << i + 1 << ": ";
        while (!valid) {
            cin >> answer;
            answer = toupper(answer); 
            if (answer == 'A' or answer == 'B' or 
                answer == 'C' or answer == 'D') {
                valid = true;
                studentAnswers[i] = answer;
            } 
            else {
                cout << "Use only an A, B, C, D or a, b, c, d!" << endl;
                cout << "Please try again." << endl;
            }
        }
    }
}

// Function to compare answers and calculate correct and incorrect counts
void checkAnswers(const char correctAnswers[], const char studentAnswers[], 
                  int &correct, int &incorrect, int size) {
    correct = 0;
    incorrect = 0;
    for (int i = 0; i < size; i++) {
        if (toupper(studentAnswers[i]) == correctAnswers[i]) {
            correct++;
        } 
        else {
            incorrect++;
        }
    }
}
/*
Sample run:

Please enter the student's answers for each of the questions.
Press Enter after typing each answer.
Please enter only an A, B, C, D or a, b, c, d for each question.
Question 1: A
Question 2: C
Question 3: B
Question 4: B
Question 5: a
Question 6: d
Question 7: d
Question 8: d
Question 9: a
Question 10: b
Question 11: v
Use only an A, B, C, D or a, b, c, d!
Please try again.
a
Question 12: F
Use only an A, B, C, D or a, b, c, d!
Please try again.
d
Question 13: a
Question 14: A
Question 15: C
Question 16: B
Question 17: A
Question 18: D
Question 19: B
Question 20: C
Questions that were answered incorrectly:
2
5
6
7
8
9
10
12
13
14
15
16
17
18
19
20


The student failed the exam.

Correct Answers: 4
Incorrect Answers: 16

*/
