
#include <stdio.h>
#include "game.h"

#define PI 3.14159265

/* ** ** local function declarations ** ** */
int countInDirection(board_conf_type board_conf, board_type board, 
  direction scoring_direction);
/* ** end local function declarations ** */


bool isWinner(board_conf_type board_conf, board_type board) {
unsigned short lineSums[NUM_SCORE_LINES] = {1, 1, 1, 1}; 

// Need to check both diagonals and both cardinal axes

direction scoring_direction;

{int line;
//Iterate over all directions:
for (int i = 0; i < 8; i++) {
  line = i % 4;
  scoring_direction.dx = (int)      nearbyint(cos(i*PI / 4.0));
  scoring_direction.dy = (int) -1 * nearbyint(sin(i*PI / 4.0));
  lineSums[line] += countInDirection(board_conf, board, scoring_direction);
}}


unsigned short lineSumMax = 1;
for (unsigned short i = 0; i < NUM_SCORE_LINES; ++i) {
  if (lineSums[i] > lineSumMax)
    { lineSumMax = lineSums[i]; }
} // end of [for]

if (lineSumMax >= board_conf.k) {
  return true;
} else {
  return false;
}
} // end of [checkWinner]


/* 
  Helper function for [checkWinner]. 
  Counts contiguous elements of the same type as origin in
  specified direction (steps) and returns the sum of these.

*/
int countInDirection(board_conf_type board_conf, board_type board, 
  direction scoring_direction) {
//
board_element elementAtCursor = 
  board[board_conf.cursor.y * board_conf.m + board_conf.cursor.x];
board_element xPos = board_conf.cursor.x, yPos = board_conf.cursor.y;
unsigned short lineSum = 0;
while (xPos + scoring_direction.dx < board_conf.m && 
       yPos + scoring_direction.dy < board_conf.n && 
       xPos + scoring_direction.dx >= 0 && 
       yPos + scoring_direction.dy >= 0) {
xPos = xPos + scoring_direction.dx;
yPos = yPos + scoring_direction.dy;
if (elementAtCursor == board[yPos * board_conf.m + xPos]) {
  ++lineSum;
} else {
  break;
} // end of [if (elementAtCursor //]
} // end of [while]

return lineSum;
} // end of [countInDirection]


// bool isIncrementInBounds(board_con
