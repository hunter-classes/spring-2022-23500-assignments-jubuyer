#pragma once
#include "Node.h"

class BSTree {
private:
    Node *root;
public:
    BSTree();
    void insert(int d);
    std::string get_debug_string();
    std::string get_debug_stringL(Node *n);
    std::string get_debug_stringR(Node *n);
    void setup();

};
