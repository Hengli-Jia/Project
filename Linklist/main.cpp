/**~*~*~* 
 Project: Singly-Linked List

 Build and procees a sorted linked list of College objects.
 The list is sorted in ascending order by the college code.
 Assume that the college code is unique.
===========================================
Name:
IDE:
*~*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "LinkedList.h"

using namespace std;

void buildList(const string &filename, LinkedList &list);
void deleteManager(LinkedList &list);
void searchManager(const LinkedList &list);
void displayManager(const LinkedList &list);

int main()
{

    string inputFileName = "colleges.txt";
    LinkedList list;

    buildList(inputFileName, list);
    displayManager(list);
    searchManager(list);
    deleteManager(list);
    displayManager(list);
    return 0;
}

/*
 This function reads data about colleges from a file and inserts them
 into a sorted linked list. The list is sorted in ascending order by code
*/
void buildList(const string &filename, LinkedList &list)
{
    ifstream inputFile(filename);
    cout << "Reading data from \"" << filename << "\"";

    if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(inputFile, line))
    {
       int rank, cost;
       string code, name;
    
       stringstream temp(line);   // create temp with data from line
       temp >> rank;              // read from temp
       temp >> code;
       temp.ignore();             // to ignore space in front of name
       getline(temp, name, ';');  // stop reading name at ';'
       temp >> cost;
       // create a College object and initialize it with data from file
       College aCollege(rank, code, name, cost);
       list.insertSorted(aCollege);
    }

    inputFile.close();
}

/* 
 Delete manager: delete items from the list until the user enters Q to quit
 deleting
 Input Parameter: list
 */
void deleteManager(LinkedList &list)
{
    string targetCode = "";

    cout << endl << " Delete" << endl;
    cout << "=======" << endl;

    while(targetCode != "Q")
    {
        cout << endl << "Enter a college code (or Q to stop deleting) : \n";
        cin >> targetCode;
        cout << endl;

        if(targetCode != "Q")
        {
            if(/* Write your code here: call deleteItem() */)
                cout << targetCode << " has been deleted!\n";
            else
                cout << "College \"" << targetCode << "\" was not found." << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____" << endl;
}

/*
 Search manager: search the list until the user enters Q to quit searching
 Input Parameter: list
 */
void searchManager(const LinkedList &list)
{
    string targetCode = "";
    College aCollege;

    cout << endl << " Search" << endl;
    cout << "=======" << endl;

    while(targetCode != "Q")
    {
        cout << "Enter a college code (or Q to stop searching) :" << endl;
        cin >> targetCode;

        if(targetCode != "Q")
        {
            if(/* Write your code here: call searchList */)
                aCollege.vDisplay();
            else
                cout << "College \"" << targetCode << "\" was not found." << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____" << endl;
}

/* 
Display manager:
 - displays the number of colleges in this list
 - calls the displayList() function upon request
Input Parameter: list
 */
void displayManager(const LinkedList &list)
{
    string action;
    
    cout << "Number of colleges: " << /* Write your code here: call getLength */ endl;
    
    cout << "Display list [Y/N]?" << endl;
    cin >> action;

    if(action == "Y" || action == "y")
    {
        /* Write your code here: call displayList() */
    }
}
