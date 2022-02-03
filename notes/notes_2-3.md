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
