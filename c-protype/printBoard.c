
#include <stdio.h>

int main(void) {

// To be input variables:
// m (cols)
unsigned int m = 3;
// n (rows)
unsigned int n = 3;
// board state : m x n char array

char board_state[m*n] = 
  {'x', ' ', 'x',
   'o', 'o', ' ',
   ' ', ' ', ' '
  }; 
// cursor position

printf("Testing.\n\n");

//0, 0 corresponds to upper left corner
for (uint i = 0; i < n; i++) {
  putc(' ', stdout); 
  for (uint j = 0; j < m; j++) {
    putc('|', stdout);
    putc(board_state[i*m + j], stdout);
  }
  putc('|', stdout);
  putc('\n', stdout);
}
