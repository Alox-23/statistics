#include "list.h"


list* init_list(uint32_t size){
  list* s = malloc(sizeof(list));
  if (!s){
    printf("Error when creating list!\n");
    return NULL;
  }

  s->size = size;
  s->values = calloc(sizeof(float), size);
  if (!s->values){
    printf("Error when creating list values!\n");
    free(s);
    return NULL;
  }

  return s;
}

void clean_list(list* s){
  if (!s){
    printf("Invalid list pointer in clean_list()!\n");
    return;
  }

  free(s->values);
  s->values = NULL;
  free(s);
  s = NULL;
}

void randomize_list(list* s){
  if (!s){
    printf("Error during list randomize_list()!\n");
    return;
  }

  for (uint32_t i = 0; i < s->size; i++){
    int random_int = rand();

    float random_float = (random_int / (float)RAND_MAX) * 100.0f;

    s->values[i] = random_float;
  }
}

float traverse_list(list* s, uint32_t k){
  if (!s || k >= s->size) return 0;
  
  float best_in_k = -1.0f;
  for (uint32_t i = 0; i < k; i++){
    if (s->values[i] > best_in_k) {
      best_in_k = s->values[i];
    }
  }
  
  float absolute_best = best_in_k;
  uint32_t best_index = 0;
  
  for (uint32_t i = 0; i < s->size; i++){
    if (s->values[i] > absolute_best) {
      absolute_best = s->values[i];
      best_index = i;
    }
  }
  
  for (uint32_t i = k; i < s->size; i++){
    if (s->values[i] > best_in_k){
      return (i == best_index) ? 1 : 0;
    }
  }
  
  if (best_index == s->size - 1) {
    return 1;
  }

  return 0;
}

void print_list(list* s){
  if (!s){
    printf("Error during list print_list()!\n");
    return;
  }

  printf("[");
  for (uint32_t i = 0; i < s->size; i++){
    printf("%.3f", s->values[i]);
    if (i != s->size-1) printf(", ");
  }
  printf("]\n");
}

void null_list(list* s){
  if (!s){
    printf("Invalid list pointer during null_list!");
    return;
  }

  for (uint32_t i = 0; i < s->size; i++){
    s->values[i] = 0;
  }
}
