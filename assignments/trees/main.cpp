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
  std::cout << "no child test" << '\n';
  BSTree *tree = new BSTree();
  tree->insert(8);
  tree->insert(3);
  tree->insert(4);
  tree->insert(2);
  std::cout <<  tree->get_debug_string() << "\n";
  tree->deleteValue(4);
  std::cout <<  tree->get_debug_string() << "\n";
  tree->deleteValue(2);
  std::cout <<  tree->get_debug_string() << "\n";

  std::cout << "one child test" << '\n';
  BSTree *tree2 = new BSTree();
  tree2->insert(8);
  tree2->insert(3);
  tree2->insert(9);
  tree2->insert(4);
  tree2->insert(2);
  tree2->insert(1);
  tree2->insert(12);
  tree2->insert(10);
  tree2->insert(13);


  std::cout <<  tree2->get_debug_string() << "\n";
  tree2->deleteValue(12);
  std::cout <<  tree2->get_debug_string() << "\n";

  //testing other stuff
  std::cout << "\n countLeaves below \n" << '\n';
  BSTree *tree3 = new BSTree();
  tree3->setup();
  std::cout <<  tree3->get_debug_string() << "\n";
  std::cout << "leaves of tree 3: " << tree3->countLeaves() << '\n';

  std::cout << "\n height below \n" << '\n';
  std::cout << "height of tree3: " << tree3->height() << '\n';
  //tree2->insert(5);
  std::cout << "height of tree2: " << tree2->height() << '\n';


  return 0;
}
