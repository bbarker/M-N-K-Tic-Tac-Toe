
#include <stdio.h>
#include "game.h"

/* void inputFlush (FILE *input_buffer) */
/* { */
/*   int ch; */

/*   do */
/*     ch = fgetc ( input_buffer );  */
/*   while ( ch != EOF && ch != '\n' );  */

/*   clearerr ( input_buffer ); */
/* } */


char inputFlush (FILE *input_buffer)
{
  int chLast;
  int ch = 0;

  do {
    chLast = ch;
    ch = fgetc ( input_buffer );
  } 
  while ( ch != EOF && ch != '\n' ); 

  clearerr ( input_buffer );
  return chLast;
}


char pauseAndGetChar(FILE *output_buffer, FILE* input_buffer) 
{ 
  fflush (output_buffer);
  return getc(input_buffer);
} 

char flushAndGetChar(FILE* input_buffer)
{
  char singleChar;
  inputFlush(input_buffer);
  singleChar = pauseAndGetChar(GAMETEXT_OUT_BUF, input_buffer);
  return singleChar;
}
