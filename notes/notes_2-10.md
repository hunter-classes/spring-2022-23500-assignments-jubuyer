## February 10

Maze solving
- Check in each direction, if there is a wall or it is the end, you're done
- Recursively solve:
  - Base cases
    - If you are at a wall
    - If you are at the goal
  - Try to solve by stepping into each of the four directions
  ```c++
  // Add self to maze
  maze[row][col] = me;
  print_maze(maze, lines); // print maze to terminal
  
  solve(maze, lines, row-1, col);
  solve(maze, lines, row+1, col);
  solve(maze, lines, row, col-1);
  solve(maze, lines, row, col-1);
  ```
 
 #### words of wisdom from zman
 - `ctrl+s` pauses terminal output
 - `ctrl+q` resumes terminal output

#### Definitions
State Space Search
- Why States?
  - Maze with 'you', where you've been, and an exit
  - Transition: move to a neighboring location (or backtrack)
  - All together create the world

- Also knowm as 
  - Depth First search
  - Recursive search
  - Exhaustive search
  - Blind search

- Downsides
  - Slow
  - Can also screw up, for example, in an open field it would check every possibility (inefficient)

Depth First search vs Depth First search:
- Depth First explores as far as possible before backtracking
- Breadth first search would only check one at a time before continuing further
  - e.g. at an intersection of left and below, it would go one left and one below, then two left and two below, etc.
  
