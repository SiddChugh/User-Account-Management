#include "slinkedlist.h"

template <class T>
SLinkedList<T>::SLinkedList()
{
  front = NULL;
  size = 0;
  back = NULL;
}

template <class T>
SLinkedList<T>::~SLinkedList()
{
  RemoveAll();
}

template <class T>
SLinkedList<T>::SLinkedList(const SLinkedList<T>& ll)
{
  CopyList(ll);
}

template <class T>
SLinkedList<T>& SLinkedList<T>:: operator=(const SLinkedList<T>& ll)
{
  if (this != &ll)
  {
    CopyList(ll);
  }
  return *this;
}

template <class T>
void SLinkedList<T>::CopyList(const SLinkedList<T>& ll)
{
  front = NULL;
  size = ll.size;

  if (ll.front != NULL)
  {
    Node<T>* firstTemp = ll.front; // first of ll
    Node<T>* first = new Node<T>(firstTemp->data); // first for new list
    front = first; // head is first
    Node<T>* temp = front;
    while (firstTemp->next != NULL)
    {
      firstTemp = firstTemp->next;
      Node<T>* first = new Node<T>(firstTemp->data);
      temp->next = first;
      temp = temp->next;
    }
  }
}

template <class T>
void SLinkedList<T>::InsertFront(T s)
{
  Node<T>*temp=new Node<T>(s);
  Node<T>*start=front;\

  if(front==NULL)
  {
    front=temp;
    temp->next=NULL;
    size++;
  }
  else
  {
    start=front;
    front=temp;
    front->next=start;
    size++;
  }
}

template <class T>
void SLinkedList<T>::InsertBack(T item)
{
  Node<T>* temp=new Node<T>(item);
  Node<T>* start=front;
  if(front==NULL)
  {
    front=temp;
    temp->next=NULL;
    size++;
  }
  else
  {
    while(start->next!=NULL)
    {
      start=start->next;
    }
    temp->next=NULL;
    start->next=temp;
    size++;
  }
}

template <class T>
T* SLinkedList<T>::Retrieve(T item)
{
  Node<T>*temp=front;
  T *data_pointer;
  while(temp!=NULL)
  {
    if(temp->data==item)
    {
      data_pointer=&temp->data;
      return data_pointer;
    }
    temp=temp->next;
  }
  return NULL;
}

template <class T>
bool SLinkedList<T>::Remove(T s)
{
  if (size != 0 && size != 1)
  {
    Node<T>* temp = front;
    Node<T>* prevnode = NULL;
    for (unsigned int i = 0; i < size; i++)
    {
      if (temp->data == s)
      {
        if (prevnode != NULL) // is prevnode is not NULL, this is the case only when its not head
        {
          prevnode->next = temp->next;
        }
        else // when head
        {
          front = front->next;
        }

        delete temp;
        size--;
        return true;
      }
      else
      {
        prevnode = temp;
        temp = temp->next;
      }
    }
    return false;
  }
  else if (size == 1)
  {
    if (front->data == s)
    {
      front = NULL;
      size--;
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

template <class T>
void SLinkedList<T>::RemoveAll()
{
  Node<T>* newnode = front;
  while (newnode != NULL)
  {
    front = front->next;
    delete newnode; // delete current
    newnode=front;
  }

  front = NULL;
  newnode=NULL;
  size = 0;
}

template <class T>
bool SLinkedList<T>::Contains(T s)const
{
  Node<T>*temp=front;
  while(temp!=NULL)
  {
    if(temp->data==s)
    {
      return true;
    }
    temp=temp->next;
  }
  return false;
}

template <class T>
int SLinkedList<T>::Size() const
{
  return size;
}

template <class T>
std::vector<T>SLinkedList<T>::Dump() const
{
  std::vector<T> v;
  Node<T>* temp = front;
  while (temp != NULL)
  {
    v.push_back(temp->data);
    temp = temp->next;
  }
  return v;
}

template <class T>
bool SLinkedList<T>::IsEmpty() const
{
    //return size==0;
    return front==NULL;
}
