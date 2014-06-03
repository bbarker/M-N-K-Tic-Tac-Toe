/* main.c - game startup for MNK-Tic-tac-toe */

#include "game.h"


int main(int argc, char **argv) {

  // print title
  fprintf(GAMETEXT_OUT_BUF, "Welcome to M-N-K-Tic-tac-toe\n\n" 
    "Please use the W-A-S-D keys (followed by ENTER) to move the cursor.\n"
    "To mark a square, press the 'T' key (followed by ENTER).\n\n");
  

  //Ask user for game specification.
  fprintf(GAMETEXT_OUT_BUF, "How many columns (three or more)?\n>>");
  board_idx m_in;
  scanf("%10hud", &m_in);
  //
  fprintf(GAMETEXT_OUT_BUF, "How many rows (three or more)?\n>>");
  board_idx n_in;
  scanf("%10hud", &n_in);

  const board_idx min_m_n = m_in < n_in ? m_in : n_in;
  const board_idx max_m_n = m_in < n_in ? n_in : m_in;
  // How to make this type safe for unsigned or signed:
  print("How many in a row to win (from %ud to %ud)?\n>>",
         (unsigned) 3, max_m_n);
  board_idx k_in;
  scanf("%10hud", &k_in);
  //
  print("How many players (up to %d)?\n>>", PLAYER_MAX);
  board_idx num_players_in;
  scanf("%10hud", &num_players_in);

  // Create board configuration.
  //
  board_conf_type board_conf = {
    .m = m_in, 
    .n = n_in, 
    .k = k_in,
    .num_players = num_players_in,
    .player_turn = 0 
  };

  // Create a blank board
  board_type board = NULL;
  const ulong board_bytes = 
    board_conf.m * board_conf.n * sizeof(board_element);
  board = (board_type) malloc(board_bytes);
  if (board == NULL) {
    fprintf(stderr, "Unable to allocate memory for board!");
    return -1;
  }

  // Execute main game loop.
  gameLoop(INIT, board_conf, board);

  return 0;
}
