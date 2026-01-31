#include "secr.h"


secr* init_secr(uint32_t size){
  secr* s = malloc(sizeof(secr));
  if (!s){
    printf("Error when creating SECR!\n");
    return NULL;
  }

  s->size = size;
  s->values = calloc(sizeof(float), size);
  if (!s->values){
    printf("Error when creating SECR values!\n");
    return NULL;
  }

  return s;
}

void clean_secr(secr* s){
  if (!s){
    printf("Invalid SECR pointer in destroy_secr()!\n");
    return;
  }

  free(s->values);
  s->values = NULL;
  free(s);
  s = NULL;
}

void randomize(secr* s){
  return;
}

int32_t traverse_secr(secr* s, uint32_t k){
  return 0;
}
