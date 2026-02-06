#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stream_utils.h"
#include "file_utils.h"

#include <time.h>

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

  char filename[256];
  memset(filename, 0, sizeof filename);

  char timebuf[256];
  memset(timebuf, 0, sizeof timebuf);

  time_t now;
  time(&now);

  struct tm* info;
  info = localtime(&now);
  strftime(timebuf, sizeof(filename), "%m-%d-%y-%H:%M:%S", info);
  snprintf(filename, sizeof(filename), "%s.tpr", timebuf);

  struct DTkL* buflist = dtkl_initialize(1000); //< initialize with 1000 max tokens (macro this later)
  
  stream_input(buflist, lbuf, sizeof lbuf); //< use the buflist
  file_save(buflist, filename);

  char tempfilename[256];
  memset(tempfilename, 0, sizeof(tempfilename));
  snprintf(tempfilename, sizeof(tempfilename), "%s.temp", filename);

  file_obfuscate(filename, tempfilename);
  remove(filename);
  rename(tempfilename, filename);

  return 0;
}

