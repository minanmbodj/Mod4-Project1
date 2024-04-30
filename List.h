#ifndef LIST_H
#define LIST_H

#include "Node.h"

using namespace std;
template <typename T>

class List{

public:
  // Constructor
  List();
  // Destructor
  ~List();

  // Get head
  Node<T>* getHead() const;

  // Insert value
  void insert(T val);
  // Remove value
  void remove(T val);
  // Remove node with specified key
  void remove(string key);
  // Find node with specified key
  Node<T>* find(string key);
  // Check if list contains value
  bool contains(T val) const;
  // Check if list contains node with specified key
  bool contains(string key) const;
  // contains method using the List<T? template
	//bool List<T>;

 // Display list
  void display() const;

 private:
  Node<T>* head_;
};


template <typename T>
List<T>::List() : head_(nullptr) {}


template <typename T>
List<T>::~List() {
  Node<T>* current = head_;
  while (current != nullptr) {
    Node<T>* next = current->getNext();
    delete current;
    current = next;
  }
}

template <typename T>
Node<T>* List<T>::getHead() const {
  return head_;
}

template <typename T>
void List<T>::insert(T val) {
  if (contains(val)) {
    return;
  }
  Node<T>* new_node = new Node<T>(val);
  if (head_ == nullptr || val < head_->getValue()) {
    new_node->setNext(head_);
    head_ = new_node;
    return;
  }
  Node<T>* current = head_;
  while (current->getNext() != nullptr && current->getNext()->getValue() < val) {
    current = current->getNext();
  }
  new_node->setNext(current->getNext());
  current->setNext(new_node);
}

template <typename T>
void List<T>::remove(T val) {
  if (!contains(val)) {
    return;
  }
  if (head_->getValue() == val) {
    Node<T>* temp = head_;
    head_ = head_->getNext();
    delete temp;
    return;
  }
  Node<T>* current = head_;
  while (current->getNext() != nullptr && current->getNext()->getValue() != val) {
    current = current->getNext();
  }
  Node<T>* temp = current->getNext();
  current->setNext(temp->getNext());
  delete temp;
}

template <typename T>
void List<T>::remove(string key) {
  if (!contains(key)) {
    return;
  }
  if (head_->getValue().getKey() == key) {
    Node<T>* temp = head_;
    head_ = head_->getNext();
    delete temp;
    return;
  }
  Node<T>* current = head_;
  while (current->getNext() != nullptr && current->getNext()->getValue().getKey() != key) {
    current = current->getNext();
  }
  Node<T>* temp = current->getNext();
  current->setNext(temp->getNext());
  delete temp;
}

template <typename T>
Node<T>* List<T>::find(string key) {
  Node<T>* current = head_;
  while (current != nullptr && current->getValue().getKey() != key) {
    current = current->getNext();
}
	return current;
}

template <typename T>
bool List<T>::contains(T val) const {
  Node<T>* current = head_;
  while (current != nullptr && current->getValue() != val) {
    current = current->getNext();
  }
  return current != nullptr;
}


template <typename T>
bool List<T>::contains(string key) const {
  Node<T>* current = head_;
  while (current != nullptr && current->getValue().getKey() != key) {
    current = current->getNext();
  }
  return current != nullptr;
}
template <typename T>
void List<T>::display() const {
	Node<T>* current = head_;
  if (head_ == nullptr) {
    cout << "empty list" << endl;
  } else {
   // Node<T>* current = head_;
    while (current != nullptr) {
      cout << current->getValue() << endl;
      current = current->getNext();
    }
  }
}



#endif

