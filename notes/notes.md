## January 31

Most important things in recursion
- Base case, (when do we know the answer?)
- Call a simpler version of the function to eventually get to the base case (generally a modification to the function call)
- Always a conditional to control everything

```
int fact(int n) {
  // conditional (when n is 0 stop recursion)
  if (n == 0) { // BASE CASE (factorial 0 equals 1)
    return 1; 
  }
  return n * fact(n-1); // function call modified 
}
```
