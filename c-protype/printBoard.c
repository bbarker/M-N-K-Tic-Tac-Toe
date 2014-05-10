
#include <stdio.h>
#include "game.h"

int printBoard(board_conf_type board_conf, board_type board) {

// iterators for the board
board_idx i; // row
board_idx j; // column


// m (cols)
const m = board_conf.m;

// n (rows)
const n = board_conf.n;

// example:
/* char board[] =  */
/*   {'x', ' ', 'x', */
/*    'o', 'o', ' ', */
/*    ' ', ' ', ' ' */
/*   };  */
// cursor position

//0, 0 corresponds to upper left corner

for (i = 0; i < n; ++i) {
  putc(TILE_EMPTY, GAME_TXT_BUF); 
  for (j = 0; j < m; ++j) {
    putc(BORDER_VERTICAL, GAME_TXT_BUF);
    if (!(i == board_conf.cursor.x && j == board_conf.cursor.y)) {
      putc(board[i*m + j], GAME_TXT_BUF);

    } else if (board[i*m + j] == TILE_EMPTY) {
      putc(CURSOR_ON_EMPTY, GAME_TXT_BUF);
    } else {
      putc(CURSOR_ON_TAKEN, GAME_TXT_BUF);
    } // end of [if (board_conf//]
  }
  putc(BORDER_VERTICAL, GAME_TXT_BUF);
  putc(ENDROW, GAME_TXT_BUF);
}

return 0;
} // end of [printBoard]
