#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "list.h"
#include "glbs.h"
#include "print.h"
#include "sim.h"

#define SEC_LIST_SIZE 100
#define DEPTH_PER_K 10000

int main(){
	srand(time(NULL));

  global_state* gs = init_gs(SEC_LIST_SIZE, DEPTH_PER_K);
  if (!gs) return clean_gs(gs);
0
  bool running = true;
  while (running){
    print_clear();
    print_main();
    char* user_input = safe_get(gs);
    char choice;
    if (!user_input) choice = 'ff';
    else choice = user_input[0];
   
    switch (choice){
      case '1':
        print_simulation_start(gs);
        user_input = safe_get(gs);
        run_simulation(gs);
        print_simulation_results(gs);
        user_input = safe_get(gs);
        break;
      case '2':
        print_settings_menu();
        break;
      case '3':
        print_help_info();
        break;
      case '0':
        print_bye();
        running = false;
        break;
      default:
        print_invalid_choice();
        user_input = safe_get(gs);
        break;
    }
  }

  return clean_gs(gs);
}
