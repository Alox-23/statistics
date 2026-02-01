#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
  float *values;
  uint32_t size;
} list;

list* init_list(uint32_t size);
void clean_list(list* s);

void randomize_list(list* s);
float traverse_list(list* s, uint32_t k);
void print_list(list* s);
