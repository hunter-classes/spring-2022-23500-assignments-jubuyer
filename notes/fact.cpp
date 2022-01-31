#include <iostream>

int fact(int n) {
  if (n == 0) {
    return 1;
  }
  return n * fact(n-1);
}

int fib(int n) {
  if (n < 2) {
    return 1;
  } else {
    return fib(n-1) + fib (n-2);
  }
}

int main () {
  // std::cout << "factorial of 3: " << fact(3) << '\n'; 
  // std::cout << "factorial of 6: " << fact(6) << '\n'; 
  // std::cout << "factorial of 4: " << fact(4) << '\n'; 

  for(int i = 0; i < 10; i++) {
    std::cout << i << " : " << fib(i) << "\n";
  }
  
  return 0;
}