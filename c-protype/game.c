/* game.c - main game loop for MNK-Tic-tac-toe */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int gameLoop(game_state) {

void *message;
if (IsMessage()) {
  message = GetMessage();
  ProcessMessage(message);
}

switch(game_state) {
case INIT:

  //Ask user for game specification.

  printf("How many columns (three or more)?\n>>");
  board_idx m_in;
  scanf("%u", &m_in);
  //
  printf("How many rows (three or more)?\n>>");
  board_idx n_in;
  scanf("%u", &n_in);
  //
  const board_idx min_m_n = m_in < n_in ? m_in : n_in;
  const board_idx max_m_n = m_in < n_in ? n_in : m_in;
  // How to make this type safe for unsigned or signed:
  printf("How many in a row to win (from %u to %u)?\n>>",
         min_m_n, max_m_n);
  board_idx k_in;
  scanf("%u", &k_in);
  //
  // Create board configuration.
  const board_conf_type board_conf = {m_in, n_in, k_in};

  // Create a blank board
  board_type board = NULL;
  const size_t board_bytes = 
    board_conf.m * board_conf.n * sizeof(board_element);
  board = (board_type) malloc(board_bytes);
  if (board == NULL) {
    fprintf(stderr, "Unable to allocate memory for board!");
    game_state = SHUTDOWN;
  }
  memset(board, (int)(unsigned char) ' ', board_bytes);
  

  // ********** TESTING ********** //
  // Show empty board:
  printBoard(board_conf, board);
  game_state = SHUTDOWN;
  // *********** End TESTING ****** //
 
  gameLoop(game_state);
case INTRO:

  gameLoop(game_state);
case MENU:
  /* It is empty for now */
  gameLoop(game_state);
case GAME:

  gameLoop(game_state);
case SHUTDOWN:
  free(board);  
  return 0;
default:
  fprintf(stderr, "Invalid game state!");
  return -1;
} // End of [switch(game_state)]
} // End of [gameLoop]
