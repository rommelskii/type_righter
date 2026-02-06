#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stream_utils.h"
#include "file_utils.h"

#define TEST_PATH "test_obf.tpr"
#define RESULT_PATH "test_result.tpr"

int main(int argc, char** argv) 
{
  char buf[8192];
  memset(buf, 0, sizeof buf);

  file_obfuscate(TEST_PATH, RESULT_PATH);

  FILE* fptr = fopen(RESULT_PATH, "r");
  if (!fptr)
  {
    perror("fopen failed");
    return 1;
  }

  while (fgets(buf, sizeof(buf), fptr) != NULL)
  {
    printf("%s", buf);
  }

  return 0;
}

