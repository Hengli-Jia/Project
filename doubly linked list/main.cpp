/**~*~*~* 
 
 Sorted Circular Doubly-Linked List ADT with Sentinel Node
 
 Build and procees a sorted linked list of College objects.
 The list is sorted in ascending order by the college code.
 Assume that the college code is unique.
===========================================
Name: Hengli Jia
IDE: VS Code IDE
*~*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>  //  toupper()

#include "LinkedListADT.h"
#include "College.h"

using namespace std;

void buildList(const string &filename, LinkedList<College> &list);
void deleteManager(LinkedList<College> &list);
void searchManager(const LinkedList<College> &list);
void displayManager(const LinkedList<College> &list);

int main()
{

    string inputFileName = "colleges.txt";
    LinkedList<College> list;

    buildList(inputFileName, list);
    displayManager(list);
    searchManager(list);
    deleteManager(list);
    displayManager(list);
    return 0;
}

/* 
 This function reads data about colleges from a file and inserts them into 
 a sorted circular doubly-linked list. The list is sorted in ascending order by code
*/
void buildList(const string &filename, LinkedList<College> &list)
{
    ifstream fin(filename);
    cout << "Reading data from \"" << filename << "\"";

    if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(fin, line))
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

    fin.close();
}

/* 
 Delete manager: calls deleteItem() in a loop.
 It propts the user to enter a college code to search for.
 If found, it diplays: targetCode - deleted 
 If not fond displays: targetCode - not found
 To stop searching the user enters Q/q.
 Input Parameter: list
 */
void deleteManager(LinkedList<College> &list)
{
    string targetCode = "";

    cout << endl << " Delete" << endl;
    cout << "=======" << endl;

    while(toupper(targetCode[0]) != 'Q')
    {
        cout << "Enter a college code (or Q/q to stop deleting):" << endl;
        getline(cin, targetCode);
        targetCode[0] = toupper(targetCode[0]);
        if(targetCode != "Q")
        {
           /*
           Write your code here: call deleteItem()
           If deleted, display: targetCode - deleted 
           if not found, display: targetCode - not found
           */
            College tempCollege;
            tempCollege.setCode(targetCode);
            if(list.deleteItem(tempCollege) )
                cout << targetCode << " -deleted" << endl;
            else
                cout <<  targetCode << "- not found" << endl;
        }
    }
    cout << "___________________END DELETE SECTION_____" << endl;
}

/* 
 Search manager: calls searchList() in a loop.
 It propts the user to enter a college code to search for.
 If found, it diplays related data calling vDisplay() of the College class.
 If not fond displays: targetCode - not found
 To stop searching the user enters Q/q.
 Input Parameter: list
 */
void searchManager(const LinkedList<College> &list)
{
    string targetCode = "";
    College aCollege;

    cout << endl << " Search" << endl;
    cout <<   "=======" << endl;;

    while(toupper(targetCode[0]) != 'Q')
    {
        cout << "Enter a college code (or Q/q to stop searching):"  << endl;
        getline(cin, targetCode);
        targetCode[0] = toupper(targetCode[0]);
        if(targetCode != "Q")
        {
           /*
           Write your code here: call searchList()
           If found, display related data calling the vDisplay() function of the College class.
           if not found, display: targetCode - not found
           */
            College tempCollege;
            tempCollege.setCode(targetCode);
            if(list.searchList(tempCollege, aCollege))
                aCollege.vDisplay();
            else
                cout << targetCode << "- not found" << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____" << endl;
}

/* 
Display manager:
 - displays the number of colleges in the list
 - calls the displayListForw() or displayListBack() upon request
Input Parameter: list
 */
void displayManager(const LinkedList<College> &list)
{
    string action;
    
    cout << "Number of colleges: " << list.getLength()<< endl;
    cout << "Display list [F/B/N]?" << endl;
    getline(cin, action);
    action[0] = toupper(action[0]);
    if (action == "F")
        /* Write your code here: to display the list from A to Z */
        list.displayListForw();
    else if (action == "B")
        /* Write your code here: to display the list from Z to A  */
        list.displayListBack();
}
