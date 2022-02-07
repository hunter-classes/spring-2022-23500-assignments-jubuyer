## February 7

### Practical uses of recursion

Solving mazes:
- Following one side of the wall
- Can lead to unsolvable issue where you are stuck on a floating object
- e.g.
``` 
|--------------------------------------------------------------|
|	 					               |
|	 					               |
|	 					               |
|	 |-----|		                               |
|	 |     | <- stuck following this object	               |
|	 |-----|		                               |
|	 					               |
|	 					               |
|--------------------------------------------------------------|
```

State Spaces:
- Each move is a new state
- A state leads to a dead end or another move
  - Hitting 3 walls after a move means you can only backtrack, end of state
  - When other moves exist, new states are made (for each direction)
  - Final solution is the accepted state

![state spaces](https://cdn.discordapp.com/attachments/904541827321974785/940270038114521189/unknown.png)

How can we represent this?
- State -> 2D array of char
- Transition -> modify the array

Using recursion to solve:
- Follow paths and when it hits a "dead end", come back down and solve next possibility
1. Global char variables -> `char me = 'Z'`, `char goal = '$'`, `char wall = '#'` 
2. Input maze data from file into array (of strings)
3. Creating the solve algorithm

### Creating the solving algorithm
- Figure out your base cases
  - Are we at the exit? If so `return;`
  - Are we at a wall? If so `return;`
- Add yourself to the maze
  - Solve function takes a row and coloumn
  - Adds self to the specified row/column
    - What if I add myself outside of the maze?
    - Base case will catch the "out of bounds" and not print the 'you' character
---
#### Maze I solved during class
![maze i solved during class](https://user-images.githubusercontent.com/66185881/152822264-3a744dca-7c86-4f9b-a501-1daaa7cc696e.png)
