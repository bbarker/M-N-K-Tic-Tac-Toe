
#include <stdio.h>
#include "game.h"


/* 
  Helper function for [checkWinner]. 
  Counts contiguous elements of the same type as origin in
  specified direction (steps) and returns the sum of these.

*/
int countInDirection(board_conf_type board_conf, board_type board, 
  int xStep, int yStep) {
//
board_element elementAtCursor = 
  board[board_conf.cursor.y * board_conf.m + board_conf.cursor.x];
board_element xPos = board_conf.cursor.x, yPos = board_conf.cursor.y;
unsigned short lineSum = 0;
while (xPos + xStep < board_conf.m && yPos + yStep < board_conf.n && 
      xPos + xStep >= 0 && yPos + yStep >= 0) {
xPos = xPos + xStep;
yPos = yPos + yStep;
if (elementAtCursor == board[yPos * board_conf.m + xPos]) {
  ++lineSum;
} else {
  break;
} // end of [if (elementAtCursor //]
} // end of [while]



return lineSum;

} // end of [countInDirection]


bool isWinner(board_conf_type board_conf, board_type board) {

//Need to check both diagonals and both cardinal axes


unsigned short lineSums[NUM_SCORE_LINES]; 

//Might be good to add these to for loop below later:

//Right and Up:
lineSums[0] = 1 + countInDirection(board_conf, board, 1, -1);
//Left and Down:
lineSums[0] += countInDirection(board_conf, board, -1, 1);


//Right and Down:
lineSums[1] = 1 + countInDirection(board_conf, board, 1, 1);
//Left and Up:
lineSums[1] += countInDirection(board_conf, board, -1, -1);

//Up:
lineSums[2] = 1 + countInDirection(board_conf, board, 0, -1);
//Down:
lineSums[2] += countInDirection(board_conf, board, 0, 1);

//Right:
lineSums[3] = 1 + countInDirection(board_conf, board, 1, 0);
//Left:
lineSums[3] += countInDirection(board_conf, board, -1, 0);


unsigned short i;
unsigned short lineSumMax = 1;
for (i = 0; i < NUM_SCORE_LINES; ++i) {
  if (lineSums[i] > lineSumMax)
    { lineSumMax = lineSums[i]; }
} // end of [for]

if (lineSumMax >= board_conf.k) {
  return true;
} else {
  return false;
}
} // end of [checkWinner]
