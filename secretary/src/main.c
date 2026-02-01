#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "list.h"
#include "glbs.h"

#define SEC_LIST_SIZE 100
#define DEPTH_PER_K 1000

int main(){
	srand(time(NULL));

  global_state* gs = init_gs(SEC_LIST_SIZE, DEPTH_PER_K);
  if (!gs) return clean_gs(gs);

  //program logic

  return clean_gs(gs);
}
