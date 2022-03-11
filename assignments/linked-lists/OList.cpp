#include <iostream>

#include "OList.h"

OList::OList() {
  head = nullptr;
}

void OList::insert(int data) {
  ONode *walker = head; //traverse list
  ONode *insertion = new ONode(data); //new node to insert
  ONode *stroller = nullptr;

  if (walker == nullptr) {
    insertion->setNext(head);
    head = insertion;
    return;
  }

  while(walker != nullptr && (data > walker->getData())) {
    stroller = walker;
    walker = walker->getNext();
  }

  if(stroller == nullptr) {
    insertion->setNext(head);
    head = insertion;
  } else {
    insertion->setNext(stroller->getNext()); //make the new node point to the old node's next node
    stroller->setNext(insertion); //make the node before where we are inserting point to the new node
  }

  return;
}

bool OList::contains(int value) {
  ONode *walker = head; //traverse list

  if (walker == nullptr) {
    return false;
  }

  while(walker != nullptr) {
    if(value == walker->getData()) {
      return true;
    }

    walker = walker->getNext();
  }

  return false;
}

int OList::get(int location) {
  int counter = 0;
  ONode *walker = head; //traverse list

  if (walker == nullptr) {
    throw std::out_of_range("Out of range");
  }

  while(walker != nullptr && counter < location) {
    walker = walker->getNext();
    counter++;
  }

  if(walker == nullptr && ((location - counter) > 1)) {
    throw std::out_of_range("Out of range");
  }

  return walker->getData();
}

void OList::remove(int location) {
  int counter = 0;
  ONode *walker = head;
  //if trying to remove the first node in the list
  if(location == 0) {
    if(walker->getNext() == nullptr) {
      head = nullptr; //if theres only one item in the list head now points to nullptr
    } else {
      walker = walker->getNext(); //or else traverse one node, set head to that node
      head=walker;
    }
    return;
  }

  //traverse to the node right before where we are trying to remove
  while(counter != (location-1) && walker != nullptr) {
    walker = walker->getNext();
    counter++;
  }

  if(walker == nullptr) {
    throw std::out_of_range("Out of range");
  }

  //traverse to the ONode we are trying to remove
  ONode *stroller = walker->getNext();
  if(stroller == nullptr) {
    throw std::out_of_range("Out of range");
  }
  //set the node before the one being removed to the removed nodes next node
  walker->setNext(stroller->getNext());
  stroller->setNext(nullptr); //set the next node for the node thats to be removed to nullptr

  return;
}

void OList::reverse() {
  ONode *walker = head; //p1
  ONode *stroller = nullptr; //p2
  ONode *trailer = nullptr; //p3
  int counter = 0;

  if(walker == nullptr || walker->getNext() == nullptr) {
    return;
  }


  stroller = walker->getNext();
  trailer = stroller->getNext();

  walker->setNext(nullptr);
  stroller->setNext(walker);


  while(trailer != nullptr) {
    walker = stroller;
    stroller = trailer;
    trailer = trailer->getNext();

    stroller->setNext(walker);
  }

  head = stroller;
  return;
}

std::string OList::toString() {
  std::string s = "";
  ONode *walker = head;
  while(walker != nullptr){
    s = s+ std::to_string(walker->getData()) + " --> ";
    walker = walker->getNext();

  }
  s = s + "nullptr";
  return s;
}

OList::~OList() {
  ONode *walker = head;
  while(walker != nullptr) {
    walker->getNext();
    delete walker;
    walker = nullptr;
  }

  head=nullptr;
}
