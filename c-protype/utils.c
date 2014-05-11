
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
  //printf ( "Press [Enter] to continue . . ." );
  fflush (output_buffer);
  return getc(input_buffer);
} 
