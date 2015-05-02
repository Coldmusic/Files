#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <string.h>

template <class T>
class LinkedList
{
  template <class V>
  class Node 
  {
    friend class LinkedList;
    private:
      Node(V d) : data(d), next(0), prev(0) {}
      V data;
      Node* prev;
      Node* next;
  };

  public:
    LinkedList();
    ~LinkedList();
    void pushBack(T);
    void pushFront(T);
    T getFront();
    T getBack();
    bool find(T);
    bool empty();
    T operator[](int);
    void remove(T);
    void print();
  private:
    Node<T>* head;
    Node<T>* tail;
};


template<class T>
LinkedList<T>::LinkedList() : head(0), tail(0) {}

template <class T>
LinkedList<T>::~LinkedList()
{
  Node<T>* next = 0, *curr = head;

  while(curr != 0) {
    next = curr->next;
    delete curr;
    curr = next;
  }
}

template <class T>
void LinkedList<T>::pushBack(T data)
{
  Node<T>* newNode = new Node<T>(data);
  
  if(head == 0) {
    head = newNode;
    tail = head;
    return;
  }

  if(head == tail) {
    head->next = newNode;
    newNode->prev = head;
    tail = newNode;
    return;
  }

  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;

}

template <class T>
void LinkedList<T>::pushFront(T data)
{
  Node<T>* newNode = new Node<T>(data);
  
  if(head == 0) {
    head = newNode;
    tail = head;
    return;
  }

  if(head == tail) {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
  }

  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

template <class T>
bool LinkedList<T>::find(T name)
{
  Node<T>* curr = head;

  while(curr != 0) {
    if(curr->data == name)
      return true;
    else curr = curr->next;
  }
  return false;
}


template <class T>
bool LinkedList<T>::empty()
{
  if(head == 0) return true;
  else return false;
}

template <class T>
void LinkedList<T>::print()
{
  Node<T>* curr = head;

  while(curr != 0) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}


template <class T>
T LinkedList<T>::getBack()
{
  if(head == 0) return 0;
  return tail->data;
}

template <class T>
T LinkedList<T>::getFront()
{
  if(head == 0) return 0;
  return head->data;
}

template <class T>
T LinkedList<T>::operator[](int num)
{
  if(num < 0) return 0;
  if(head == 0) return 0;

  Node <T>* curr = head;
  int count = num;
  while(curr != 0) {
    if(count == 0) return curr->data;
    if(count > 0) {
      --count;
      curr = curr->next;
    }
  }
  
  return 0;  
}

template <class T>
void LinkedList<T>::remove(T name)
{
  if(empty()) return;
   
  Node<T>* curr = head, *prev = 0;

  while(curr != 0) {
    //if(curr->data == name) break;
    //else {
      prev = curr;
      curr = curr->next;
    //}
  }

  if(curr == 0) return;

  if(prev == 0) {
    curr->next->prev = 0;
    head = curr->next;
    //delete curr;
    return;
  }
 
  if(curr == tail) {
    curr->prev->next = 0;
    tail = curr->prev;
    //delete curr;
    return;
  }

  prev->next = curr->next;
  curr->next->prev = prev;
  //delete curr;
 
}
