
#include <stdio.h>
#include "game.h"

#define PI 3.14159265

/* ** ** local function declarations ** ** */
int countInDirection(board_conf_type board_conf, board_type board, 
  direction scoring_direction);
bool isInBounds(board_conf_type board_conf, int x, int y);
/* ** end local function declarations ** */




bool isWinner(board_conf_type board_conf, board_type board) {
unsigned short lineSums[NUM_SCORE_LINES] = {1, 1, 1, 1}; 
//Iterate over all directions:
int line;
direction scoring_direction;
for (int i = 0; i < 8; i++) {
  line = i % NUM_SCORE_LINES;
  scoring_direction.dx = (int)      nearbyint(cos(i*PI / 4.0));
  scoring_direction.dy = (int) -1 * nearbyint(sin(i*PI / 4.0));
  lineSums[line] += countInDirection(board_conf, board, scoring_direction);
}
//
unsigned short lineSumMax = 1;
for (unsigned short i = 0; i < NUM_SCORE_LINES; ++i) {
  if (lineSums[i] > lineSumMax)
    { lineSumMax = lineSums[i]; }
} // end of [for]
//
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
const int dx = scoring_direction.dx;
const int dy = scoring_direction.dy;
//
board_element elementAtCursor = 
  board[board_conf.cursor.y * board_conf.m + board_conf.cursor.x];
board_element xPos = board_conf.cursor.x, yPos = board_conf.cursor.y;
unsigned short lineSum = 0;
while (isInBounds(board_conf, xPos + dx, yPos + dy)) {
  xPos = xPos + dx;
  yPos = yPos + dy;
  if (elementAtCursor == board[yPos * board_conf.m + xPos]) {
    ++lineSum;
  } else {
    break;
  } // end of [if (elementAtCursor //]
} // end of [while]

return lineSum;
} // end of [countInDirection]


bool isInBounds(board_conf_type board_conf, int x, int y) {
if (x < board_conf.m && y < board_conf.n && 
    x >= 0           && y >= 0)
{
  return true;
} else {
  return false;
} // end of [if]
} // end of [isInBounds]
