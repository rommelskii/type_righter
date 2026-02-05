#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct DTk 
{
  char* ct;
  struct DTk* next;   
  struct DTk* prev;   
};

struct DTkL
{
  size_t length;
  size_t capacity;
  struct DTk* head;
  struct DTk* tail;
};

struct DTk* dtk_create(const char* ct, size_t len_ct);
void dtk_free(struct DTk* del);

struct DTkL* dtkl_initialize(const size_t CAPACITY);
struct DTk* dtkl_append(struct DTkL* list, struct DTk* add);

struct DTk* st_push(struct DTkL* list, struct DTk* add);
struct DTk* st_pop(struct DTkL* list);

void dtkl_print(struct DTkL* list);


