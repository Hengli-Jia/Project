#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    ifstream inFile;
    int num;
    int max=INT_MIN; ;
    inFile.open("nums.txt");
    if(inFile){
        while(inFile >> num){
            if(max < num){
                max = num;
            } 
        }  
        cout << max << endl;
        inFile.close();  
    }
    else {
        cout << "Error opening file." << endl;
    }
}
