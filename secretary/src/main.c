#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "list.h"

#define SEC_LIST_SIZE 100
#define DEPTH_PER_K 1000

int main(){
	srand(time(NULL));

  list *secr_list = init_list(SEC_LIST_SIZE);
  list *fail_list = init_list(DEPTH_PER_K);
  list *afk_list = init_list(SEC_LIST_SIZE); // average-fail-per-k list (not "away from keyboard" !!)
  if (!secr_list) return 1;
  if (!fail_list) return 1;
  if (!afk_list) return 1;
  
  int k = 5;
  for (int i = 0; i < 100; i++){
    randomize_list(secr_list);
    printf("\n");
    print_list(secr_list);
    printf("Failure = %f\n", traverse_list(secr_list, k));
  }

  clean_list(secr_list);
  return 0;
}
