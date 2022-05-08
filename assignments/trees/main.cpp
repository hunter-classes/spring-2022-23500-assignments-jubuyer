#include <iostream>
#include "Node.h"
#include "BSTree.h"
int main()
{

  BSTree *t = new BSTree();
  t->setup();

  std::cout <<  t->get_debug_string() << "\n";
  int v = 5;


  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }

  v = 22;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }
  v = 8;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }

  t->rinsert(22);
  std::cout <<  t->get_debug_string() << "\n";
  t->insert(3);
  std::cout <<  t->get_debug_string() << "\n";

  v = 126;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
  }
  t->rinsert(126);
  std::cout <<  t->get_debug_string() << "\n";

  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }

  v = 22;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }
  //   std::cout << t->treesum() << "\n";


  //testing delete stuff
  std::cout << "\n\n\n delete below \n" << '\n';
  BSTree *tree = new BSTree();
  tree->insert(8);
  tree->insert(3);
  tree->insert(4);
  tree->insert(2);
  std::cout <<  tree->get_debug_string() << "\n";
  tree->deleteValue(2);
  std::cout <<  tree->get_debug_string() << "\n";

  return 0;
}
