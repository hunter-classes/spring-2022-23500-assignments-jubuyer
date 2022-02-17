#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>

char knight = 'N';
char wall = '#';
char cell = '.';
char visited=',';
int counter = 1;

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

void solve(std::string board[], int lines, int row, int col, int cells, bool &solved){
  if (counter==(cells-1)){
    solved = true;
    return;
  }
  if (board[row][col]==wall ||
      board[row][col]==knight ||
      board[row][col]==visited){
    return;
  }

  board[row][col]=knight;
  counter++;
  usleep(80000);
  print_board(board,lines);

  if (!solved) solve(board,lines,row-1,col+2,cells,solved);
  if (!solved) solve(board,lines,row+1,col+2,cells,solved);
  if (!solved) solve(board,lines,row+1,col-2,cells,solved);
  if (!solved) solve(board,lines,row-1,col-2,cells,solved);
  if (!solved) solve(board,lines,row-2,col+1,cells,solved);
  if (!solved) solve(board,lines,row-2,col-1,cells,solved);
  if (!solved) solve(board,lines,row+2,col-1,cells,solved);
  if (!solved) solve(board,lines,row+2,col-1,cells,solved);


  if (!solved) {
    board[row][col]=visited;
  }
}
int main(int argc, char const *argv[]) {
  std::cout << "Project 1: Jubayer A" << '\n';
  std::string board[27];
  int lines;
  lines = load_board("board.dat",board);

  std::cout << "[2J;\n";
  print_board(board,lines);
  bool solved = false;
  int cells = 25;
  solve(board,lines,2,2,cells,solved);
  print_board(board,lines);
  std::cout << "Done!\n";
  return 0;
}
