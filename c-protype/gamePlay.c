
#include <stdio.h>
#include "game.h"




bool isWinner(board_conf_type board_conf, board_type board) {
unsigned short lineSums[NUM_SCORE_LINES]; 

// Need to check both diagonals and both cardinal axes
// Might be good to add these to for loop below later:

direction scoring_direction;

/* //Right and Up: */
/* scoring_direction.dx = 1; */
/* scoring_direction.dy = -1; */
/* lineSums[0] = 1 + countInDirection(board_conf, board, scoring_direction); */
/* //Left and Down: */
/* scoring_direction.dx = -1, 1}; */
/* lineSums[0] += countInDirection(board_conf, board, scoring_direction); */

/* //Right and Down: */
/* scoring_direction = {1, 1}; */
/* lineSums[1] = 1 + countInDirection(board_conf, board, scoring_direction); */
/* //Left and Up: */
/* scoring_direction = {-1, -1}; */
/* lineSums[1] += countInDirection(board_conf, board, scoring_direction); */

/* //Up: */
/* scoring_direction = {0, -1}; */
/* lineSums[2] = 1 + countInDirection(board_conf, board, scoring_direction); */
/* //Down: */
/* scoring_direction = {0, 1}; */
/* lineSums[2] += countInDirection(board_conf, board, scoring_direction); */

/* //Right: */
/* scoring_direction = {1, 0}; */
/* lineSums[3] = 1 + countInDirection(board_conf, board, scoring_direction); */
/* //Left: */
/* scoring_direction = {-1, 0}; */
/* lineSums[3] += countInDirection(board_conf, board, scoring_direction); */




//Iterate over all directions:
for (int i = -1; i <= 1; ++i) {
  for (int j = -1; j <= 1; ++i) {
    if (i != 0 || j != 0) {
      scoring_direction.dx = i;
      scoring_direction.dy = j;


    }
  } // end of [for (int j//]
} // end of [for (int i//]


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


unsigned short mapDirectionToLine(direction scoring_direction) {
int 
// x + x*y + (x-y) // x-y doesn't work for first directions
// best to just use condtionals

}
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
