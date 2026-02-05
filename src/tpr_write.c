#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stream_utils.h"
#include "file_utils.h"

#define LINE_MAX 2048

/**
 * EXPERIMENTAL MACROS (remove later)
 */
#define TEST_PATH "test.tpr"

/**
 * file: tpr_write.c
 * Contains entrypoint for writing entries
 */


int main() 
{
  char lbuf[LINE_MAX];
  memset(lbuf, 0, sizeof(lbuf));

  char choice[256];
  memset(choice, 0, sizeof choice);

  struct DTkL* buflist = dtkl_initialize(1000); //< initialize with 1000 max tokens (macro this later)
  
  for (;;)
  {
    stream_input(buflist, lbuf, sizeof lbuf); //< use the buflist
    file_save(buflist, TEST_PATH);

    printf("continue? (y/n): ");

    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = '\0';
    if (strncmp(choice, "y", 256) == 0) 
    {
      break;
    }
  }
  return 0;
}

