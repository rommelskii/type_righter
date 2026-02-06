#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stream_utils.h"
#include "file_utils.h"

#define TEMP_PATH "test_result.tpr"

int main(int argc, char** argv) 
{
  assert(argc == 2);

  char buf[8192];
  memset(buf, 0, sizeof buf);

  FILE* isopen = fopen(argv[1], "r");
  if (!isopen)
  {
    perror("fopen failed");
    return -1;
  }
  fclose(isopen);

  file_obfuscate(argv[1], TEMP_PATH);

  FILE* fptr = fopen(TEMP_PATH, "r");
  if (!fptr)
  {
    perror("fopen failed");
    return 1;
  }

  while (fgets(buf, sizeof(buf), fptr) != NULL)
  {
    printf("%s", buf);
  }

  remove(TEMP_PATH);
  fclose(fptr);

  return 0;
}

