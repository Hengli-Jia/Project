/**~*~*~* 
  Specification file for the LinkedList ADT class
=================================================
Name: Hengli Jia
*~*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListNodeADT.h"

template <class T>
class LinkedList
{
private:
    ListNode<T> *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    void insertSorted(const T &);
    bool deleteItem(const T &);
    
    void displayListForw() const;
    void displayListBack() const;
    bool searchList(const T &, T &) const;
};

/*
 Constructor - creates an empty circular doubly-linked list wiht a sentinel node
*/
template <class T>
LinkedList<T>::LinkedList()
{
    head = new ListNode<T>; // head points to the sentinel node
    head->setNext(head);     
    head->setPrev(head);
    length = 0;              
}

/*
   insertSorted() creates a new node with dataIn copied to its data member
   and inserts it into the sorted doubly-linked list at the right location
   to keep the list sorted.
*/
template <class T>
void LinkedList<T>::insertSorted(const T &dataIn)
{
    ListNode<T> *newNode;  // A new node
    ListNode<T> *pCur;     // To traverse the list
    ListNode<T> *pPre;     // The previous node
    
    // Allocate a new node and store dataIn there.
    newNode = new ListNode<T>(dataIn);

    // Initialize pointers
    pCur = head->getNext();

    // Find location: skip all nodes whose code is less than dataIn's code
   // while (pCur != head && newNode->getData().getCode() > pCur->getData().getCode())
    while (pCur != head && newNode->getData() > pCur->getData())
    {
        pCur = pCur->getNext();
    }
    
    // Insert the new node between pPre and pCur
    pPre = pCur->getPrev();
    pPre->setNext(newNode);
    newNode->setNext(pCur);
    newNode->setPrev(pPre);
    pCur->setPrev(newNode);
    
    // Update the counter
    length++;
}

/*
 The deleteItem function searches for a node in a sorted doubly-linked list.
 target - is an object that contains the key we search for
 If found, the node is removed from the list, deleted from memory, and returns true.
 If not found, returns false.
*/
//bool LinkedList::deleteItem(string target)
template <class T>
bool LinkedList<T>::deleteItem(const T &target)
{
    /* Write your code here */
    ListNode<T> *pCur;       // To traverse the list
    ListNode<T> *pPre;       // To point to the previous node
    bool deleted = false;
    
    // Initialize pointers
    pCur = head->getNext();

    while (pCur != head && pCur->getData() < target){ pCur = pCur->getNext();}
    // If found, delte the node
    if (pCur->getData() == target)
    {
        pCur->getPrev()->setNext(pCur->getNext());
        pCur->getNext()->setPrev(pCur->getPrev());
        delete pCur;
        
        deleted = true;
        length--;
    }
    return deleted;
}

/*
 displayListForw() - traverses the doubly-linked list forwards 
 showing the value stored in each node 
*/
template <class T>
void LinkedList<T>::displayListForw() const
{
     ListNode<T> *pCur =  head->getNext();  // To move through the list


     // While pCur points to a node, traverse the list.
     while (pCur != head)
     {
         // Display the value in this node.
         // pCur->getData().hDdisplay();
         
          std::cout << pCur->getData();
         
         // Move to the next node.
         pCur = pCur->getNext();
    }
    std::cout << std::endl;
}

/*
 displayListBack() - traverses the doubly-linked list backwards 
 showing the value stored in each node 
*/
template <class T>
void LinkedList<T>::displayListBack() const
{
   /* Write your code here */
     ListNode<T> *pCur =  head->getPrev();  // To move through the list

     // Position pCur: skip the head of the list.
     pCur = head->getPrev();

     // While pCur points to a node, traverse the list.
     while (pCur != head)
     {
         // Display the value in this node.
         // pCur->getData().hDdisplay();
         
          std::cout << pCur->getData();
         
         // Move to the next node.
         pCur = pCur->getPrev();
    }
    std::cout << std::endl;
}


/*
 The searchList function looks for a target in the sorted doubly-linked list.
 target - is an object that contains the key we search for
 If found, returns true and copies the data in that node to the output parameter dataOut.
 If not found return false and does not change dataOut.
*/
template <class T>
bool LinkedList<T>::searchList(const T &target, T &dataOut) const
{
   /* Write your code here */
   ListNode<T> *pCur =  head->getNext();      // To traverse the list
   bool found = false;                  // To indicate if the target was found
   while (pCur != head && target > pCur->getData())
   { 
       // Move to the next node.
       pCur = pCur->getNext();
   }
   // If found, copy data to the output parameter, and change the flag to true
  /* Write your code here */
    if(target == pCur->getData()){
       found = true;   
       dataOut = pCur->getData();
     }
    return found;
}

/*
 Destructor                                       
 This function deletes every node in the list, including the sentinel node.   
*/
template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T> *pCur;     // To traverse the list
    ListNode<T> *pNext;    // To hold the address of the next node
    
    // Position nodePtr: skip the head of the list
    pCur = head->getNext();
    // While pCur is not at the end of the list...
    while(pCur != head)
    {
        // Save a pointer to the next node.
        pNext = pCur->getNext();
        
        // Delete the current node.
        delete pCur;
        
         // Position pCur at the next node.
        pCur = pNext;
    }
    
    delete head; // delete the sentinel node
}

#endif

