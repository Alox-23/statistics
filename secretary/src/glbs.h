#ifndef GLBS_H
#define GLBS_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "list.h"

typedef struct {
  list *secr_list;
  list *fail_list;
  list *afk_list;
  uint32_t sec_list_size;
  uint32_t depth_per_k;
} global_state;

global_state* init_gs(uint32_t sec_list_size, uint32_t depth_per_k);
int clean_gs(global_state* gs);
void restart_gs(global_state** gs, uint32_t sec_list_size, uint32_t depth_per_k);

#endif
