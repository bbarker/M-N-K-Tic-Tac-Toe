/* main.c - game startup for MNK-Tic-tac-toe */

#include <stdio.h>
#include "game.h"


int main(int argc, char **argv) {

  // print title
  fprintf(stdout, "M-N-K-Tic-tac-toe\n");


  //Ask user for game specification.
  printf("How many columns (three or more)?\n>>");
  board_idx m_in;
  scanf("%10hu", &m_in);
  //
  printf("How many rows (three or more)?\n>>");
  board_idx n_in;
  scanf("%10hu", &n_in);
  //
  const board_idx min_m_n = m_in < n_in ? m_in : n_in;
  const board_idx max_m_n = m_in < n_in ? n_in : m_in;
  // How to make this type safe for unsigned or signed:
  printf("How many in a row to win (from %u to %u)?\n>>",
         (unsigned) 3, max_m_n);
  board_idx k_in;
  scanf("%10hu", &k_in);
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
    return -1;
  }
  memset(board, (int)(unsigned char) ' ', board_bytes);


  // Execute main game loop.
  gameLoop(INIT, board_conf, board);

  return 0;
}
