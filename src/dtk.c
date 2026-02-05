#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dtk.h"

struct DTk* dtk_create(const char* ct, size_t len_ct)
{
  if (ct == NULL)
  {
    fprintf(stderr, "dtk_create error: ct cannot be NULL\n");
    return NULL;
  }

  struct DTk* ret = (struct DTk*)malloc(sizeof(struct DTk));
  ret->ct = (char*)malloc(sizeof(char)*len_ct+1);
  ret->next = NULL;
  ret->prev = NULL;
  memcpy(ret->ct, ct, len_ct+1);
  
  return ret;
}

void dtk_free(struct DTk* del) 
{
  if (del == NULL)
  {
    fprintf(stderr, "dtk_free error: del cannot be null\n");
    return;
  }
  if(del->ct == NULL) 
  {
    fprintf(stderr, "dtk_free error: ct of del cannot be null\n");
    return;
  }

  free(del->ct);
  free(del);

  return;
}

struct DTkL* dtkl_initialize(const size_t CAPACITY) 
{
  struct DTkL* ret = (struct DTkL*)malloc(sizeof(struct DTkL));

  ret->length = 0;
  ret->capacity = CAPACITY;

  ret->head = NULL;
  ret->tail = NULL;

  return ret;
}

struct DTk* dtkl_append(struct DTkL* list, struct DTk* add) 
{
  if (list == NULL || add == NULL)
  {
    fprintf(stderr, "dtkl_append error: list or add cannot be null\n");
    return NULL;
  }
  if (list->length >= list->capacity) 
  {
    fprintf(stderr, "dtkl_append error: length is already at capacity\n");
    return NULL;
  } 

  if (list->length == 0) 
  {
    list->tail = add;
    list->head = list->tail;
  } else {
    list->tail->next = add;
    add->prev = list->tail;
    list->tail = list->tail->next;
  }
  
  list->length++;

  return list->tail;
}

//Note: this is just a wrapper around dtkl_append
struct DTk* st_push(struct DTkL* list, struct DTk* add) 
{
  return dtkl_append(list, add);
}

struct DTk* st_pop(struct DTkL* list) 
{
  if (list->length == 0) 
  {
    fprintf(stderr, "st_pop error: stack is empty\n");
    return NULL;
  } 

  struct DTk* ret = list->tail;
  if (list->length == 1) 
  {
    list->tail = NULL;
    list->head = NULL;
  } else {
    list->tail = list->tail->prev;
    list->tail->next = NULL;
  }

  list->length--; 

  return ret;
}

void dtkl_print(struct DTkL* list)
{
  if (list == NULL) 
  {
    fprintf(stderr, "dtkl_print error: list cannot be null\n");
    return;
  }

  if (list->length == 0) 
  {
    printf("List is empty.\n");
    return;
  }

  struct DTk* iter = list->head;
  while (iter != NULL) 
  {
    printf("%s\n", iter->ct);
    iter = iter->next;
  }
}


