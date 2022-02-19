#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fstream>

char knight = 'N';
char wall = '#';
char cell = '.';
char visited=',';
int counter = 1;

std::vector<std::vector<int>> solution (8, std::vector<int> (8, 0));


int load_board(std::string filename, std::string *board){
  std::ifstream infile(filename);
  int i=0;
  while(std::getline(infile,board[i])){
    i++;
  }
  return i;
}

void print_board(std::string board[],int lines){
  std::cout << "[0;0H\n";
  for(int i = 0; i < lines; i++){
    std::cout << board[i] << "\n";
  }
}

void print_solution() {
  int sol_size = solution.size();
  for(int i = 0; i < sol_size; i++) {
    int sol_in_size = solution[i].size();
    for(int j = 0; j < sol_in_size; j++) {
      if(solution[i][j] < 10) {
        std::cout << "0" << solution[i][j] << ":";
      } else {
        std::cout << solution[i][j] << ":";
      }
    }
    std::cout << '\n';
  }
}

void solve(std::string board[], int lines, int row, int col, int goal, bool &solved){
  if(counter == goal+1) {
    solved = true;
    return;
  }

  if(board[row][col] == wall ||
     board[row][col] == visited ||
     board[row][col] == knight) {
    return;
  }

  // std::string temp = std::to_string(counter);
  board[row][col] = knight;
  solution[row-2][col-2] = counter;
  //usleep(100);
  print_board(board,lines);
  //print_solution();
  counter++;

  if (!solved) solve(board,lines,row-1,col+2,goal,solved);
  if (!solved) solve(board,lines,row+1,col+2,goal,solved);
  if (!solved) solve(board,lines,row+1,col-2,goal,solved);
  if (!solved) solve(board,lines,row-1,col-2,goal,solved);
  if (!solved) solve(board,lines,row-2,col+1,goal,solved);
  if (!solved) solve(board,lines,row-2,col-1,goal,solved);
  if (!solved) solve(board,lines,row+2,col-1,goal,solved);
  if (!solved) solve(board,lines,row+2,col-1,goal,solved);

  if (!solved) {
    board[row][col]=cell;
    counter--;
    solution[row-2][col-2] = 0;
  }
}

int main(int argc, char const *argv[]) {
  std::cout << "Project 1: Jubayer A" << '\n';
  std::string board[13];

  int lines;
  lines = load_board("board.dat",board);

  std::cout << "[2J;\n";
  print_board(board,lines);
  bool solved = false;
  int goal = 64;
  solve(board,lines,2,2,goal,solved);
  print_board(board,lines);
  std::cout << "Done!\n";

  print_solution();
  return 0;
}
