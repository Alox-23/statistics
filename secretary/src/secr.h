#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
  float *values;
  uint32_t size;
} secr;

secr* init_secr(uint32_t size);
void clean_secr(secr* s);

void randomize(secr* s);
int32_t traverse_secr(secr* s, uint32_t k);
