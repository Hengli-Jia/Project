/*
This C++ program will prompt the user for an integer that 
will be searched for in the array using a binary search. 

Date: 12/04/2024
*/

#include <iostream>
#include <fstream>

using namespace std;

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int size);

// Function to perform binary search
int binarySearch(const int arr[], int target, int size) ;

// Function to calculate the mean of the array
double findMean(int arr[], int size);

int main() {
    ifstream inFile("nums.txt");
    ofstream outFile("output.txt");

    // Check if file opened successfully
    if (!inFile) {
        cout << "Error: Could not open nums.txt" << endl;
        return 0;
    }

    // Read numbers from the file into the array
    int num;
    int temp[100] = {0};
    int size = 0;
    while (inFile >> num) {
       temp[size] = num;
       size ++;
    }
    int arr[size] = {0};
    for (int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
    inFile.close();

    // Prompt the user for the number to search
    int target;
    cout << "Enter an integer to search for: " << endl;
    cin >> target;


    // Output the array size and contents
    cout << "This array has " << size << " items." << endl;
    cout << "The array entered by the user is as follows:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Write the original array to the output file
    outFile << "This array has " << size << " items." << endl;
    outFile << "The array entered by the user is as follows:" << endl;
    for (int i = 0; i < size; i++) {
        outFile << arr[i] << " ";
    }
    outFile << endl;

    // Sort the array
    bubbleSort(arr, size);

    // Output the sorted array
    cout << "The sorted array is as follows:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Write the sorted array to the output file
    outFile << "The sorted array is as follows:" << endl;
    for (int i = 0; i < size; i++) {
        outFile << arr[i] << " ";
    }
    outFile << endl;

    // Perform binary search
    int position = binarySearch(arr, target, size);

    // Output the search results
    cout << "The item searched for is " << target << endl;
    if (position != -1) {
        cout << "The value " << target << " is in position number "; 
        cout << position << " of the list." << endl;
    } 
    else {
        cout << "The value " << target << " is not in the array." << endl;
    }

    // Write the search results to the output file
    outFile << "The item searched for is " << target << endl;
    if (position != -1) {
        outFile << "The value " << target << " is in position number " ;
        outFile<< position << " of the list." << endl;
    } 
    else {
        outFile << "The value " << target << " is not in the array." << endl;
    }

    // Calculate the mean
    double mean = findMean(arr, size);

    // Output the mean
    cout << "The mean of all the elements in the array is " << mean << endl;
    outFile << "The mean of all the elements in the array is " << mean << endl;
    
    // Close the output file
    outFile.close();
    return 0;
}

void bubbleSort(int arr[], int size) {
    int n = size;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int binarySearch(const int arr[], int target, int size) {
    int left = 0, right =  size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid + 1; 
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

double findMean(int arr[],int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + arr[i];
    }
    return sum / (size / 1.0);
}
/*
Sample Run:

Enter an integer to search for:
100
This array has 12 items.
The array entered by the user is as follows:
22 -4 5 100 39 20 88 10 55 3 10 78
The sorted array is as follows:
-4 3 5 10 10 20 22 39 55 78 88 100
The item searched for is 100
The value 100 is in position number 12 of the list.
The mean of all the elements in the array is 35.5
*/