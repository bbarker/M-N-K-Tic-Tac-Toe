/* game.c - main game loop for MNK-Tic-tac-toe */

#include <stdio.h>
#include "game.h"

bool IsMessage(void) {
  bool message_waiting = 0;
  // check messages here
  if (message_waiting) {
    return true;
  } else {
    return false;
  }
}


void* GetMessage(void) {
  void *message;
  // code to retrieve message from queue goes here */
  return message;
}

void ProcessMessage(void *message) {
  //process message here
}




int gameLoop(int game_state, board_conf_type board_conf, 
  board_type board) {

void *message;
if (IsMessage()) {
  message = (void *) GetMessage();
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
