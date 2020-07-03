/**
  *Description: Declaration of a hash table class 
  *Uses separate chaining with a singly-linked list
  */

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "SLinkedList.h"
#include "accounts.h"

#include <math.h> // needed for Hash function

class HashTable
{
private:
  SLinkedList<UserAccount>* table;  
  unsigned int size;    // number of items stored
  unsigned int maxsize; // size of underlying array

  /**
    *hash function, uses Horner's method
    *Assume input std::string consists only of lower-case a to z
    */
  int Hash(std::string input) const;

  /**
    *helper function to find smallest prime number greater than supplied 
    *parameter
    */
  int SmallestPrime(int n) const;

  /**
    *helper function to determine whether a number is prime
    */
  bool IsPrime(int n) const;

public:
  /**
    *default constructor
    *creates an array of size 101
    */
  HashTable();

  /**
    *parameterized constructor
    *creates an array of size = smallest prime number > 2n
    */
  HashTable(int n);

  /**
    *copy constructor
    *Creates deep copy of sourceht
    */
  HashTable(const HashTable& sourceht);

  ~HashTable();

  /**
    *overloaded assignment operator
    */
  HashTable& operator=(const HashTable& sourceht);

  /**
    *Insertion
    *If item does not already exist, inserts and returns true
    *  otherwise returns false
    */
  bool Insert(UserAccount value);

  /**
    *Removal
    *If item exists, removes and returns true
    *  otherwise returns false
    */
  bool Remove(UserAccount value);

  /**
    *Search
    *Returns true if item exists, false otherwise
    */
  bool Search(UserAccount value) const;

  /**
    *Returns the number of items stored in the hash table
    */
  int Size() const;

  /**
    *Returns the size of the underlying array
    */
  int MaxSize() const;

  /**
    *Returns the load factor as size / maxsize.
    *Note that due to separate chaining, load factor can be > 1.
    */
  double LoadFactor() const;

  /**
    *Resizes the hashtable into a larger array.
    *Return false if n is smaller than current array size.
    *Else, set array size to the smallest prime number larger than n
    *  and re-hash all contents into the new array, delete the old array and 
    *  return true.
    */
  bool Resize(unsigned int n);
};

#endif