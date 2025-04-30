/**~*~*~* 
 Specification file for the LinkedList class
===========================================
*~*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "College.h"

class LinkedList
{
private:
    struct ListNode
    {
        College college;
        ListNode *next;
    };

    ListNode *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    void insertSorted(College);
    bool deleteItem(string);
    void displayList() const;
    bool searchList(string, College &) const;
};

#endif
