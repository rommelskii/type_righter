#include <stdlib.h>
#include <stdio.h>

#include "dtk.h"

#define KEY "WeDoNotTalkAboutTheKey"

void xor_cize(char* str, size_t len, const char* key);

int main() 
{
  struct DTkL* buflist = dtkl_initialize(1000);
  char buf[1024];
  memset(buf, 0, sizeof(buf));

  size_t idx = 1;

  for (;;) 
  {
    system("clear");
    printf("%zu: ", idx);

    if (fgets(buf, sizeof(buf), stdin) != NULL)
    {
      buf[strcspn(buf, "\n")] = '\0';
    }

    if (strcmp(buf, "exit") == 0) break;
    struct DTk* newnode = dtk_create(buf, strlen(buf));
    xor_cize(newnode->ct, strlen(newnode->ct), KEY);
    dtkl_append(buflist, newnode);

    ++idx;
  }
  system("clear");
  
  dtkl_print(buflist);
  return 0;
}

void xor_cize(char* str, size_t len, const char* key) 
{
  if (str == NULL || key == NULL) return;

  size_t keylen = strlen(key);
  for (size_t i=0; i<len; ++i) 
  {
    str[i] ^= key[i % keylen];
  }
}
