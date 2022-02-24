#include <iostream>

#include "List.h"


List::List(){
  head = nullptr;
}

void List::insert(std::string data){
  //create a Node
  Node *new_node = new Node(data);

  //insert the new node
  new_node->setNext(head);
  head = new_node;
}

std::string List::toString(){
  std::string s = "";
  Node *walker = head;
  while(walker != nullptr){
    s = s+ walker->getData() + "-->";
    walker = walker->getNext();

  }
  s = s + "nullptr";
  return s;
}

void List::locate(int location, std::string data) {
  int counter = 0;
  Node *walker = head;
  Node *insertion = new Node(data);

  if(location==0) {
    insertion->setNext(head);
    head = insertion;
    return;
  }
  while(counter != (location-1) && walker != nullptr) {
    walker = walker->getNext();
    counter++;
  }

  insertion->setNext(walker->getNext());
  walker->setNext(insertion);

  return;
}

void List::remove(int location) {
  int counter = 0;
  Node *walker = head;
  if(location == 0) {
    if(walker->getNext() == nullptr) {
      head = nullptr;
    } else {
      walker = walker->getNext();
      head=walker;
    }
    return;
  }

  while(counter != (location-1) && walker != nullptr) {
    walker = walker->getNext();
    counter++;
  }

  Node *stroller = walker->getNext();
  walker->setNext(stroller->getNext());
  stroller->setNext(nullptr);

  return;
}
