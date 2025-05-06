/**~*~*~* 
 Implementation file for the College class
===========================================
Name: Hengli Jia
*~*/

#include <iostream>
#include <iomanip>
#include <string>

#include "College.h"

using namespace std;


// Constructor   
College::College()
{
    rank = -1;
    code = "";
    name = "";
    cost = -1;
}


// Overloaded Constructor
College::College(int rk = -1, string cd = "", string nm = "", int ct = -1)
{
    rank = rk;
    code = cd;
    name = nm;
    cost = ct;
}

/*
 Displays the values of the College object member variables
 on one line (horizontal display)
*/
void College::hDdisplay() const
{
    cout << left;
    cout << " " << setw(4) << code << "  ";
    cout << " " << setw(2) << rank << "  ";
    cout << " " << setw(27)<< name << "  ";
    cout << right;
    cout << " " << setw(7) << cost << " ";
    cout << left << endl;
}

/*
 Displays the values of the College object member variables
 one per line (vertical display)
*/
void College::vDisplay() const
{
    cout << "              Rank: " << rank << endl;
    cout << "       School Name: " << name << endl;
    cout << "Cost of Attendance: $" << cost << endl;
}

// overloaded operators
/*
 Overloaded << operator. Gives cout the ability to directly display College objects
 using the same format as in hDisplay()
*/
ostream& operator<<(ostream& lhs, const College& rhs)
{
    lhs << left;
    lhs << " " << setw(4) << rhs.code << "  ";
    lhs << " " << setw(2) << rhs.rank << "  ";
    lhs << " " << setw(27)<< rhs.name << "  ";
    lhs << right;
    lhs << " " << setw(7) << rhs.cost << " ";
    lhs << left;
    return lhs;
}
/*
Write your code here to define the oveloaded stream insertion operator ( << )
*/

bool College::operator== (const College& rhs) const {return (code == rhs.code);}
bool College::operator< (const College& rhs) const {return (code < rhs.code);}
bool College::operator> (const College& rhs) const{return (code > rhs.code);}

