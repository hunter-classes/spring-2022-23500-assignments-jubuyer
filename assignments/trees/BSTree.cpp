#include <iostream>
#include "Node.h"
#include "BSTree.h"
/*
 *
 BST - Binary Search Tree

 ordered tree where it's either empty or given a node N, all the
 values in N's left subtree are less than the value in N and all the
 values in N's right subtree are greater than the value in N.
*/

BSTree::BSTree() {
  root = nullptr;
}

std::string BSTree::traverse(Node *n) {
  std::string a,b,c;

  if (n==nullptr){
    return "";
  } else {


    /*
     *  pre-order traversal

     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree

     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());


     * post-order traversal

     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node

     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());


    */

    /*
	in-order traversal

	1. recurse left subtree
	2. process node
	3. recurse right subtree
    */

    a =  traverse(n->getLeft());
    b = std::to_string(n->getData());
    c =  traverse(n->getRight());

    return a + ", " + b+ ", " + c;


  }
};

std::string BSTree::get_debug_string() {
  return traverse(root);
};

void BSTree::setup() {
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);

}

int BSTree::search(int value) {
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }

  }

  // if we get here then the value isn't
  // in the tree

  // normally, if we had a tree of objects
  // we could return null but since we only have
  // an int, we can't return an int to represent
  // not found so we'll throw an exception

  throw 1; // we should define our exceptions.



}

int BSTree::rsearch(int value) {
  return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p) {
  if(p == nullptr) {
    throw TREE_ERR_NULL;
  }

  int pval = p->getData();
  if(pval == value) {
    return value;
  }

  if(pval > value) {
    return rsearch(value, p->getLeft());
  }
  if(pval < value) {
    return rsearch(value, p->getRight());
  }

  throw TREE_ERR_VALUE_DNE;
}

void BSTree::insert(int value) {

  // make a new node
  Node *newnode = new Node(value);

  // search for where the node would go as a leaf
  // that is, search until we get to null
  // we can use the piggyback strategy of having
  // a second pointer trail the lead pointer
  Node *p = root;
  Node *trailer;


  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;
    if (p->getData() == value){
      // do the stuff when the node is already in the tree
      return;
    }
    else if (p->getData() < value){
      p = p->getRight();
    } else {
      p = p->getLeft();
    }
  }

  // handle the special case of the tree
  // being empty (null)
  if (root==nullptr){
    root=newnode;
  } else {
    // trailer points to the node ABOVE where the new node
    // will go.
    // we have to figure out if newnode goes on the
    // left of trailer or on the right of trailer
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }

  }
}

void BSTree::rinsert(int value) {
  rinsert(value, root);
}

void BSTree::rinsert(int value, Node *p) {
  Node *newnode = new Node(value);

  if(root==nullptr) {
    p = newnode;
  }

  if (p->getData() == value){
    return;
  }

  // if(p==nullptr && trailer != nullptr) {
  //   if (trailer->getData() < value){
  //     trailer->setRight(newnode);
  //     return;
  //   } else {
  //     trailer->setLeft(newnode);
  //     return;
  //   }
  // }
  //
  // trailer = p;

  if(p->getData() > value) {
    if(p->getLeft()==nullptr) {
      p->setLeft(newnode);
      return;
    }
  }
  if(p->getData() < value) {
    if(p->getRight()==nullptr) {
      p->setRight(newnode);
      return;
    }
  }


  if(p->getData() > value) {
    rinsert(value, p->getLeft());
  }
  if(p->getData() < value) {
    rinsert(value, p->getRight());
  }
}

int BSTree::countLeaves(Node *n) {
  int leaves = 0;
  Node *p = n;

  if(p == nullptr) {
    return leaves;
  } else {
    if (p->getRight() == nullptr && p->getLeft() == nullptr) {
      leaves++;
    }
  }

  leaves += countLeaves(p->getRight());
  leaves += countLeaves(p->getLeft());

  return leaves;
}

int BSTree::countLeaves() {
  return this->countLeaves(root);
}

int BSTree::height(Node *n, int& current) {
  Node *p = n;

  if(root == nullptr) {
    return 0;
  }

  if(p->getLeft() != nullptr || p->getRight() != nullptr) {
    current++;
    //std::cout << "\nplus" << '\n';
  }

  if (p->getLeft() != nullptr && p->getRight() != nullptr) {
    height(p->getLeft(), current);
    height(p->getRight(), current);
  } else if (p->getLeft() != nullptr) {
      height(p->getLeft(), current);
    } else if (p->getRight() != nullptr) {
        height(p->getRight(), current);
      }

  return current;
}

int BSTree::height() {
  int counter = 1;
  this->height(root, counter);
  return counter;
}

bool BSTree::cousins(int dat1, int dat2) {
  Node *t = root;
  bool found = false;
  bool found2 = false;
  int counter = 0;
  int counter2 = 0;

  while (t != nullptr && !found){
    int tval = t->getData();
    if (tval==dat1){
      found = true;
    }

    counter++;
    if (tval < dat1){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }
  }

  t = root;
  if(found) {
    while (t != nullptr && !found2){
      int tval = t->getData();
      if (tval==dat2){
        found2 = true;
      }

      counter2++;
      if (tval < dat2){
        t = t->getRight();
      } else {
        t = t->getLeft();
      }
    }
  }

  if(counter == counter2) {
    return true;
  }

  return false;
}

void BSTree::deleteValue(int value) {
  Node *p = root;
  Node *trailer;

  while (p != nullptr) {

    if(p->getData() == value) {
      //if the node has no children (leaf)
      if((p->getRight() == nullptr) && (p->getLeft() == nullptr)) {
        //is p to the right or left of trailer? set that to nullptr
        if(trailer->getRight() == p) {
          trailer->setRight(nullptr);
          // std::cout << "deleteR" << '\n';
          // std::cout <<  "t: " << trailer->getData() << '\n';
          return;
        } else {
          trailer->setLeft(nullptr);
          // std::cout << "deleteL" << '\n';
          // std::cout <<  "t: " << trailer->getData() << '\n';
          return;
        }
      }
      //if the node has one child
      if((p->getRight() != nullptr) && (p->getLeft() == nullptr)) {
        //does p have a child to the right only?
        //is p to the right or left of trailer? set that to p's child
        if(trailer->getRight() == p) {
          trailer->setRight(p->getRight());
          return;
        } else {
          trailer->setLeft(p->getRight());
          return;
        }
      }

      if((p->getRight() == nullptr) && (p->getLeft() != nullptr)) {
        //does p have a child to the left only?
        //is p to the right or left of trailer? set that to p's child
        if(trailer->getRight() == p) {
          trailer->setRight(p->getLeft());
          return;
        } else {
          trailer->setLeft(p->getLeft());
          return;
        }
      }
      //if the node has 2 children
      if((p->getRight() != nullptr) && (p->getLeft() != nullptr)) {
        Node *temp = p->getLeft();
        while(temp->getRight() != nullptr) {
          temp = temp->getRight();
        }
        int holder = temp->getData();
        this->deleteValue(holder);
        p->setData(holder);
      }
    } else if (p->getData() < value){
        trailer = p;
        p = p->getRight();
      } else {
        trailer = p;
        p = p->getLeft();
      }

      // std::cout << "n: " << p->getData() << '\n';
      // std::cout <<  "t: " << trailer->getData() << '\n';
  }

  return;
}
