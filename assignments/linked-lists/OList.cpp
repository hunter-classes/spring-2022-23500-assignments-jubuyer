#include <iostream>

#include "OList.h"

OList::OList() {
  head = nullptr;
}

void OList::insert(int data) {
  ONode *walker = head; //traverse list
  ONode *insertion = new ONode(data); //new node to insert

  if(walker->getNext() == nullptr) {
    insertion->setNext() = head;
    head = insertion;
    return;
  }

  while(walker != nullptr) {
    if(data < walker->getData()) {
      insertion->setNext(walker->getNext()); //make the new node point to the old node's next node
      walker->setNext(insertion); //make the node before where we are inserting point to the new node
      return;
    }

    walker = walker->getNext();
  }

  //if the function hasn't yet returned it means the insertion data is greatest
  //so we can set next to nullptr and insert it
}

bool OList::contains(int value) {

}

int OList::value(int location) {

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

}

std::string OList::toString() {
  std::string s = "";
  ONode *walker = head;
  while(walker != nullptr){
    s = s+ walker->getData() + "-->";
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
