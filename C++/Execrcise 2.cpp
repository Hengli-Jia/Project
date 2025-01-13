#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void input(string arr[], int SIZE){
    ifstream inFile;
    inFile.open("dic-1.txt");
    if (!inFile) {
        cout << "Error: File could not be opened." << endl;
    }
    else{
        for(int i = 0; i < SIZE; i++){
            inFile >> arr[i];
        }
        inFile.close();
    }
}
void slectionSort(string arr[], int SIZE){   
    string temp;
    for (int i = 0; i < SIZE - 1; i++){
        int index = i;
        for (int j = i + 1; j < SIZE; j++){
            if (arr[index] > arr[j] ){
                index = j;
            }
        }
        if (index != i){
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }  
    }
}
void binarySearch(string arr[], int SIZE, string word){
    int left = 0;
    int right = SIZE -1;
    bool judge = true;
    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == word){
            cout << "Word found!" << endl;
            judge = false;
            break;
        }         
        else if (arr[mid] < word){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }  
    if (judge){
        cout << "Word not found!" << endl;    
    }   
}
int main(){
    const int SIZE = 20000; 
    string arr[SIZE];
    string word;

    input(arr , SIZE);
    slectionSort(arr, SIZE);

    while(1){
        cout << "Enter a word." << endl;
        cin >> word;
        if ( word == "stop"){
            break;
        }
        else{
            binarySearch(arr, SIZE, word);
        }
    }
    return 0;
}