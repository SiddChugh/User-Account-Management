// Description: Definition of a template singly-linked-list class 

#ifndef _SLINKEDLIST_H_
#define _SLINKEDLIST_H_

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

template <class T>
class Node
{
public:
  T data;
  Node<T>* next;

  // default constructor
  Node(T value)
  {
    data = value;
    next = NULL;
  }
};

template <class T>
class SLinkedList
{
private:
  int size; // number of items stored in list
  Node<T>* front; // references to the front
  Node<T>* back;  //  and back of the list

  /**
    *helper function for deep copy
    *Used by copy constructor and operator=
    */
  void CopyList(const SLinkedList& ll);

  /**
    *helper function for deep delete
    *Used by destructor and copy/assignment
    */
  void DeleteList();

public:
  SLinkedList();

  /**
    *copy constructor, performs deep copy of list elements
    */
  SLinkedList(const SLinkedList& ll);

  ~SLinkedList();

  /**
    *Inserts an item at the front of the list
    *POST:  List contains item at front
    *PARAM: item = item to be inserted
    */
  void InsertFront(T item);

  /**
    *Inserts an item at the back of the list
    *POST:  List contains item at back
    *PARAM: item = item to be inserted
    */
  void InsertBack(T item);

  /**
    *Removes the first occurrence of the supplied parameter
    *Removes and returns true if found, otherwise returns false if parameter 
    *is not found or list is empty
    */
  bool Remove(T item);

  /**
    *Removes all items in the list
    */
  void RemoveAll();

  /**
    * Returns size of list
    */
  int Size() const;

  /**
    *Returns whether the list is empty
    */
  bool IsEmpty() const;

  /**
    *Returns existence of item
    */
  bool Contains(T item) const;

  /**
    *Returns a pointer to the in-place list item or NULL if item not found
    */
  T* Retrieve(T item);

  /**
    *Returns a std::vector containing the list contents using push_back
    */
  std::vector<T> Dump() const;

  /**
    *must work in the following cases:
    *list2 = list1 -> general case
    *list2 = list2 -> should do nothing
    */
  SLinkedList& operator=(const SLinkedList& ll);

  void printForward();
};

#endif
