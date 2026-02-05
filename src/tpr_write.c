#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stream_utils.h"
//#include "file_utils.h"

#define LINE_MAX 2048

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

  for (;;)
  {
    stream_input(lbuf, sizeof lbuf);
    //file_save(lbuf, sizeof lbuf);

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

