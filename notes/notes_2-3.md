## February 3

Iterative vs Recursion
- Iterative version of fibonacci was faster and immediate
- Recursive version not as efficient, slows down around n=29

Why?
- Stack is used up by recursive calling of same function
- recalculates functions which is inefficient
- Leads to slower runtime


Tail-end Recursion
- Makes recursion more efficient?
- adds "loop" to recursive function
- Implements variables from loop into parameter of recursive function
- Not really used in c++, more natural in functional languages

Dynamic Programming
- Memoization
- Writing things down and saving it for later
- Can allow you to speed up the function, by saving previous calculation
- Fibonacci example
  - Have an array to store the fib numbers that havent been calculated, and if it has, simply call it -> as fast as iterative version
  - Example: 
  ```
    int fibtable[10000];
    int fib_dyn(int n){

      if (n < 2){
        return 1;
      } else if (fibtable[n] != 0){
          return fibtable[n];
      } else {
          int tmp = fib_dyn(n-1) + fib_dyn(n-2);
          fibtable[n]=tmp;
          return tmp;
      }
    }
  ```
