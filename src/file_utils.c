#include "file_utils.h"

#include <stdio.h>
#include <stdlib.h>

//    file_save(buflist, TEST_PATH);

void file_save(struct DTkL* buflist, const char* PATH) 
{
  if (buflist == NULL || PATH == NULL) {
    fprintf(stderr, "file_save error: buflist or PATH cannot be null\n");
    return;
  }
  if (buflist->length == 0)
  {
    fprintf(stderr, "file_save error: buflist is empty \n");
    return;
  }

  char buf[2048];
  memset(buf, 0, sizeof(buf));

  FILE* pfile = fopen(PATH, "a");
  if(pfile == NULL)
  {
    fprintf(stderr, "file_save error: failed to create %s\n", PATH);
    return;
  }

  for (struct DTk* iter = buflist->head; iter != NULL; iter = iter->next) 
  {
    memcpy(buf, iter->ct, strnlen(iter->ct, sizeof(buf)));
    iter->ct[strcspn(iter->ct, "\0")] = '\n';
    fputs(iter->ct, pfile);
    memset(buf, 0, sizeof(buf));
  }

  fclose(pfile);
}
