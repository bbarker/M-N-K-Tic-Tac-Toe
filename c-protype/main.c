/* main.c - game startup for MNK-Tic-tac-toe */

#include <stdio.h>
#include "game.h"

char *title_string = "M-N-K-Tic-tac-toe";

bool IsMessage(void) {
  bool message_waiting = 0;
  // check messages here
  if (message_waiting) {
    return true;
  } else {
    return false;
  }
}


void *GetMessage(void) {
  void *message;
  // code to retrieve message from queue goes here */
  return message;
}

void ProcessMessage(void *message) {
  //process message here
}

int main(int argc, char **argv) {

  fprintf(stdout, title_string);

  // Execute main game loop.
  gameLoop(INIT);

  return 0;
}
