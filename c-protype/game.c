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

size_t board_bytes;
char decision;
switch(game_state) {
case INIT:
  board_bytes = board_conf.m * board_conf.n * sizeof(board_element);
  memset(board, (int)(unsigned char) TILE_EMPTY, board_bytes);  

  board_point cursor_init =  {
   .x = ceilf(((float) (board_conf.m - 1)) / 2.0), 
   .y = ceilf(((float) (board_conf.n - 1)) / 2.0)
  };
  board_conf.cursor = cursor_init;

  game_state = GAME;
  return gameLoop(game_state, board_conf, board);
case INTRO:

  return gameLoop(game_state, board_conf, board);
case MENU:
  //Flush buffer:
  while((decision = getchar()) != '\n' && decision != EOF) {}
  fprintf(GAME_TXT_BUF, "Play again? [y/n]>>");
  decision = (char) tolower(getc(stdin));
  if (decision == 'y') {
    game_state = INIT;
  } else if (decision == 'n') {
    game_state = SHUTDOWN;
  } else {
    fprintf(GAME_TXT_BUF, "Invalid choice, please try again.");
  }

  return gameLoop(game_state, board_conf, board);
case GAME:

  printBoard(board_conf, board);

  //
  // I/O here
  //

  if (checkWinner(board_conf, board)) {
    game_state = MENU;
  };
  

  return gameLoop(game_state, board_conf, board);
case SHUTDOWN:
  free(board);  
  return 0;
default:
  fprintf(stderr, "Invalid game state!");
  return -1;
} // End of [switch(game_state)]
} // End of [gameLoop]
