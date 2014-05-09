/* game.c - main game loop for MNK-Tic-tac-toe */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int gameLoop(int game_state, board_conf_type board_conf, 
  board_type board) {

void *message;
if (IsMessage()) {
  message = GetMessage();
  ProcessMessage(message);
}

switch(game_state) {
case INIT:
  
  // ********** TESTING ********** //
  // Show empty board:
  printBoard(board_conf, board);
  game_state = SHUTDOWN;
  // *********** End TESTING ****** //
 
  return gameLoop(game_state, board_conf, board);
case INTRO:

  return gameLoop(game_state, board_conf, board);
case MENU:
  /* It is empty for now */
  return gameLoop(game_state, board_conf, board);
case GAME:

  return gameLoop(game_state, board_conf, board);
case SHUTDOWN:
  free(board);  
  return 0;
default:
  fprintf(stderr, "Invalid game state!");
  return -1;
} // End of [switch(game_state)]
} // End of [gameLoop]
