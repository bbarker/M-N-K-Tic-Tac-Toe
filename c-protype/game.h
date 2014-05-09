/* Game definitions and prototypes */

#ifndef __MNK_TIC_TAC_TOE__
#define __MNK_TIC_TAC_TOE__

#include <stdbool.h>

/* ** Game types ** */
typedef char board_element;
typedef board_element* board_type;
typedef unsigned short int board_idx;
//
struct board_conf_type {
  board_element m, n, k;
};
typedef struct board_conf_type board_conf_type;

/* ** Game functions ** */
//
// main game loop 
//
int gameLoop(int);
//
// Print current board
//
int printBoard(board_conf_type, board_type);

#define INIT     0
#define INTRO    1
#define MENU     2
#define GAME     3
#define SHUTDOWN 4

#endif


/* ** End of [game.h] ** */
