
#include <stdio.h>
#include "game.h"

int printBoard(board_conf_type bconf, board_type board) {

// iterators for the board
board_idx i; // row
board_idx j; // column


// m (cols)
const m = bconf.m;

// n (rows)
const n = bconf.n;
// board state : m x n char array

/* char board[] =  */
/*   {'x', ' ', 'x', */
/*    'o', 'o', ' ', */
/*    ' ', ' ', ' ' */
/*   };  */
// cursor position

//0, 0 corresponds to upper left corner
for (i = 0; i < n; ++i) {
  putc(' ', stdout); 
  for (j = 0; j < m; ++j) {
    putc('|', stdout);
    putc(board[i*m + j], stdout);
  }
  putc('|', stdout);
  putc('\n', stdout);
}

return 0;
} // end of [main]
