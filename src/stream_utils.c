#include <stdio.h>
#include <stdlib.h>

#include "dtk.h"
#include "stream_utils.h"

#define KEY "WeDoNotTalkAboutTheKey"

void stream_input(char* lbuf, size_t stream_len) 
{
  struct DTkL* buflist = dtkl_initialize(1000);
  //char buf[1024];
  //memset(buf, 0, sizeof(buf));

  size_t idx = 1;

  for (;;) 
  {
    system("clear");
    printf("%zu: ", idx);

    if (fgets(lbuf, stream_len, stdin) != NULL)
    {
      lbuf[strcspn(lbuf, "\n")] = '\0';
    }

    if (strcmp(lbuf, "exit") == 0) break;
    struct DTk* newnode = dtk_create(lbuf, strlen(lbuf));
    stream_obfuscate(newnode->ct, strlen(newnode->ct), KEY);
    dtkl_append(buflist, newnode);

    ++idx;
  }
  system("clear");
  
  dtkl_print(buflist);
  return;
}

void stream_obfuscate(char* str, size_t len, const char* key) 
{
  if (str == NULL || key == NULL) return;

  size_t keylen = strlen(key);
  for (size_t i=0; i<len; ++i) 
  {
    str[i] ^= key[i % keylen];
  }

  return;
}
