#include "file_utils.h"

#include <stdio.h>
#include <stdlib.h>


void file_path_norm(const char* PATH, char* NEW_PATH)
{
  if (PATH == NULL || NEW_PATH == NULL) 
  {
    fprintf(stderr, "file_path_norm error: path or new path cannot be null\n");
    return;
  }

  char buf[2048];
  memset(buf, 0, sizeof(buf));
  snprintf(buf, sizeof(buf), "/tmp/type_righter/%s", PATH);

  memcpy(NEW_PATH, buf, strlen(buf)+1);

  return;
}

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

void file_obfuscate(const char* ORIGINAL_PATH, const char* RESULT_PATH) 
{
  FILE* fptr = fopen(ORIGINAL_PATH, "rb");
  FILE* obf = fopen(RESULT_PATH, "wb");

  if (!fptr || !obf)
  {
    perror("fopen failed");
    return;
  }
  
  char buf[FILE_OBF_LEN];
  size_t bytes_read;
  size_t total_processed = 0;
  size_t key_len = strlen(KEY);

  while ((bytes_read = fread(buf, 1, sizeof(buf), fptr)) > 0)
  {
    xor_cize_offset(buf, bytes_read, KEY, key_len, total_processed);

    fwrite(buf, 1, bytes_read, obf);

    total_processed += bytes_read;
  }

  fclose(fptr);
  fclose(obf);

  return;
}

void xor_cize_offset(char* str, size_t len, const char* key, size_t keylen, size_t file_offset)
{
    if (str == NULL || key == NULL || keylen == 0) return;

    for (size_t i = 0; i < len; ++i) 
    {
        str[i] ^= key[(file_offset + i) % keylen];
    }
}

