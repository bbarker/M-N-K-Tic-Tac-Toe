/* Game definitions and prototypes */

#ifndef __MNK_TIC_TAC_TOE__
#define __MNK_TIC_TAC_TOE__

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INIT     0
#define INTRO    1
#define MENU     2
#define GAME     3
#define SHUTDOWN 4


// Some tile definitions
#define CURSOR_ON_EMPTY '?'
#define CURSOR_ON_TAKEN '!'
#define TILE_EMPTY      ' '
#define BORDER_VERTICAL '|'
#define ENDROW          '\n'


// Other game definitions
#define GAME_TXT_BUF    stdout
#define NUM_SCORE_LINES 4

/* ** Game types ** */
typedef char board_element;
typedef board_element* board_type;
typedef unsigned short int board_idx;
//
struct board_point {
  board_idx x, y;
};
typedef struct board_point board_point;
//
struct board_conf_type {
  const board_idx m, n, k;
  board_point cursor;
};
typedef struct board_conf_type board_conf_type;



/* ** Game functions ** */
//
// main game loop 
//
int gameLoop(int, board_conf_type, board_type);
//
// Print current board
//
int printBoard(board_conf_type, board_type);
//
// Check to see if there is a winner.
//
int checkWinner(board_conf_type board_conf, board_type board);

#endif


/* ** End of [game.h] ** */
