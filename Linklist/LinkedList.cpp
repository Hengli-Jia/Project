/**~*~*~* 
 Implementation file for the LinkedList class
===========================================
Name:
*~*/

#include <iostream>
#include "LinkedList.h"

using namespace std;

/*
 Constructor
 This function allocates and initializes a sentinel node
      A sentinel (or dummy) node is an extra node added before the first data record.
      This convention simplifies and accelerates some list-manipulation algorithms,
      by making sure that all links can be safely dereferenced and that every list
      (even one that contains no data elements) always has a "first" node.
*/
LinkedList::LinkedList()
{
    head = new ListNode; // head points to the sentinel node
    head->next = NULL;
    length = 0;
}

/*
   insertSorted() creates a new node with dataIn copied to its college member
   and inserts it into the linked list at the right location to keep the list
   sorted by code.
*/
void LinkedList::insertSorted(College dataIn)
{
    ListNode *newNode;  // A new node
    ListNode *pCur;     // To traverse the list
    ListNode *pPre;     // The previous node
    
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->college = dataIn;

    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find location: skip all nodes whose code is less than dataIn's code
    while (pCur && newNode->college.getCode() > pCur->college.getCode())
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // Insert the new node between pPre and pCur
    pPre->next = newNode;
    newNode->next = pCur;
    
    // Update the counter
    length++;
}

/*
 The deleteItem() function searches for a node
 with target as its code value. The node, if found, is
 removed from the list and deleted from memory.
*/
bool LinkedList::deleteItem(string target)
{
    ListNode *pCur;       // To traverse the list
    ListNode *pPre;       // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pPre = head;
    pCur = head->next;

    // Find node containing the target: Skip all nodes whose code is less than target
    while (pCur && pCur->college.getCode() < target)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    
    // If found, delete the node
    if (pCur && pCur->college.getCode() == target)
    {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        length--;
    }
    return deleted;
}

/*
 displayList() shows the value stored in each node of the linked list
 pointed to by head, except for the sentinel node.                              
*/
void LinkedList::displayList() const
{
     ListNode *pCur;  // To move through the list

     // Position pCur: skip the sentinel node
     pCur = head->next;

     // While pCur points to a node, traverse the list.
     while (pCur)
     {
         // Display the value in this node.
         pCur->college.hDdisplay();
         
         // Move to the next node.
         pCur = pCur->next;
    }
    cout << endl;
}

/*
 The searchList function looks for a target college
 in the sorted linked list: if found, returns true
 and copies the data in that node to the output parameter
*/
bool LinkedList::searchList(string target, College &dataOut) const
{
    bool found = false; // assume target not found
    ListNode *pCur;         // To move through the list
    
    /* Write your code here */
    
    return found;
}

/*
 Destructor                                       
 This function deletes every node in the list, including the sentinel node.    
*/
LinkedList::~LinkedList()
{
   ListNode *pNext;    // To hold the address of the next node
    
    // While head is not at the end of the list...
    while (head)      // head != nullptr
    {
        // Save a pointer to the next node.
        pNext = head->next;
        // Delete the head node
        delete head;
        
        // Position head at the next node.
        head = pNext;
    }
}
