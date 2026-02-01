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
  if (!s){
    printf("Error during list traverse_list!\n");
    return -1.f;
  }

  if (k >= s->size){
    printf("Error during list traver_list! K-value out of bounds!\n");
    return -1.f;
  }

  float k_list_max_value = 0;
  for (uint32_t i = 0; i < k; i++){
    if (s->values[i] > k_list_max_value) k_list_max_value = s->values[i];
  }

  float selected_value = 0;
  for (uint32_t i = k; i < s->size; i++){
    //we found our listetary!
    if (s->values[i] > k_list_max_value){
      selected_value = s->values[i];
      break;
    }
  }

  float actual_max_value = k_list_max_value;
  for (uint32_t i = k; i < s->size; i++){
    //find real max_value
    if (s->values[i] > actual_max_value){
      actual_max_value = s->values[i];
    }
  }

  float failure = actual_max_value - selected_value;
  if (failure < 0) failure *= -1; // this condition shouldnt happen - but just in case lol
  
  return failure;
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
