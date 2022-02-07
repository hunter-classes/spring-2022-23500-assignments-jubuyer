## February 7

### Practical uses of recursion

Solving mazes:
- Following one side of the wall
- Can lead to unsolvable issue where you are stuck on a floating object
- e.g.
``` 
|--------------------------------------------------------------|
|	 														   |
|	 														   |
|	 														   |
|	 		|-----|											   |
|	 		|	  | <- stuck following this object			   |
|	 		|-----|											   |
|	 														   |
|	 														   |
|--------------------------------------------------------------|
```

State Spaces:
- Each move is a new state
- A state leads to a dead end or another move
  - Hitting 3 walls after a move means you can only backtrack, end of state
  - When other moves exist, new states are made (for each direction)
  - Final solution is the accepted state

How can we represent this?
- State -> 2D array of char
- Transition -> modify the array

Using recursion to solve: