/* Game definitions and prototypes */

#ifndef __MNK_TIC_TAC_TOE__
#define __MNK_TIC_TAC_TOE__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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


// Controls
#define KEY_BUFFER stdin
#define KEY_UP     'w'
#define KEY_DOWN   's'
#define KEY_LEFT   'a'
#define KEY_RIGHT  'd'
#define KEY_MARK   't'

// Other game definitions
#define GAMETEXT_OUT_BUF    stdout
#define NUM_SCORE_LINES 4

// Error values
#define UNKNOWN_ERROR -100


/* ** Game types ** */
typedef char board_element;
typedef board_element* board_type;
typedef unsigned short int board_idx;
//
struct direction {
  int dx, dy;
};
typedef struct direction direction;
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
bool isWinner(board_conf_type board_conf, board_type board);

#endif




/* ** Utility functions ** */
//
// Input buffer flush and get character using 
// only C-standard functions.
//
char flushAndGetChar(FILE* input_buffer);



/* ** End of [game.h] ** */
