
#include <stdio.h>

int main(void) {

typedef unsigned int board_idx;
// To be input variables:
// m (cols)
board_idx m = 3;
// n (rows)
board_idx n = 3;
// board state : m x n char array

char board_state[] = 
  {'x', ' ', 'x',
   'o', 'o', ' ',
   ' ', ' ', ' '
  }; 
// cursor position

//0, 0 corresponds to upper left corner
board_idx i;
board_idx j;
for (i = 0; i < n; i++) {
  putc(' ', stdout); 
  for (j = 0; j < m; j++) {
    putc('|', stdout);
    putc(board_state[i*m + j], stdout);
  }
  putc('|', stdout);
  putc('\n', stdout);
}

} // end of [main]
