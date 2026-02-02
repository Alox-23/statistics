#include "print.h"

void print_clear(){
  printf("\033[2J\033[1;1H");
}

void print_bye(){
  printf("Goodbye!\n");
}

void print_main(){
  printf("\n┌─────────────────────────────────────┐\n");
  printf("│     SECRETARY PROBLEM SIMULATOR     │\n");
  printf("├─────────────────────────────────────┤\n");
  printf("│  1. Run Simulation                  │\n");
  printf("│  2. Configuration                   │\n");
  printf("│  3. Help & Information              │\n");
  printf("│  0. Exit                            │\n");
  printf("└─────────────────────────────────────┘\n");
};

void print_simulation_start(global_state *gs) {
    if (!gs) return;
    
    printf("\n┌─────────────────────────────────────┐\n");
    printf("│          SIMULATION MODE            │\n");
    printf("├─────────────────────────────────────┤\n");
    printf("│  Running secretary problem          │\n");
    printf("│  simulation with parameters:        │\n");
    printf("│                                     │\n");
    printf("│  • Candidates (n): %-10u       │\n", gs->sec_list_size);
    printf("│  • Sampling depth: %-10u       │\n", gs->depth_per_k);
    printf("│                                     │\n");
    printf("│  Press Enter to start               │\n");
    printf("└─────────────────────────────────────┘\n");
}

void print_settings_menu() {
  printf("\n┌─────────────────────────────────────┐\n");
  printf("│           CONFIGURATION             │\n");
  printf("├─────────────────────────────────────┤\n");
  printf("│  Instructions:                      │\n");
  printf("│                                     │\n");
  printf("│  1. Set candidate pool size (n)     │\n");
  printf("│  2. Set number of iterations        │\n");
  printf("│                                     │\n");
  printf("│  Press Enter to start               │\n");
  printf("└─────────────────────────────────────┘\n");
}

void handle_settings_change(global_state *gs){
  printf("\n┌─────────────────────────────────────┐\n");
  printf("│           CONFIGURATION             │\n");
  printf("├─────────────────────────────────────┤\n");
  printf("│  Enter number of Candidates         │\n");
  printf("└─────────────────────────────────────┘\n");
  char* candidate_input = safe_get(gs);
  uint32_t candidate_count = atoi(candidate_input);
  print_clear();
  printf("\n┌─────────────────────────────────────┐\n");
  printf("│           CONFIGURATION             │\n");
  printf("├─────────────────────────────────────┤\n");
  printf("│  Enter number of Iterations         │\n");
  printf("└─────────────────────────────────────┘\n");
  char* iter_input = safe_get(gs);
  uint32_t iter_count = atoi(iter_input);
 
  restart_gs(&gs, candidate_count, iter_count);
}

void print_help_info(global_state *gs) {
  printf("\n┌─────────────────────────────────────┐\n");
  printf("│          HELP & INFORMATION         │\n");
  printf("├─────────────────────────────────────┤\n");
  printf("│  About the Secretary Problem:       │\n");
  printf("│                                     │\n");
  printf("│  • Also known as optimal stopping   │\n");
  printf("│  • Goal: Select best candidate      │\n");
  printf("│  • Strategy: Reject first k, then   │\n");
  printf("│    pick next best                   │\n");
  printf("│  • Optimal k ≈ n / e (≈37%% of n)    │\n");
  printf("│  • Success rate: ~37%%               │\n");
  printf("│                                     │\n");
  printf("│  Parameters:                        │\n");
  printf("│  • Candidates (n): %-10u       │\n", gs->sec_list_size);
  printf("│  • Sampling depth: %-10u       │\n", gs->depth_per_k);
  printf("│                                     │\n");
  printf("│  Press Enter to continue...         │\n");
  printf("└─────────────────────────────────────┘\n");
}

void print_invalid_choice() {
  printf("\n┌─────────────────────────────────────┐\n");
  printf("│          INVALID CHOICE             │\n");
  printf("├─────────────────────────────────────┤\n");
  printf("│  Press Enter to continue...         │\n");
  printf("└─────────────────────────────────────┘\n");
}

void print_simulation_results(global_state *gs){
  printf("\n┌─────────────────────────────────────┐\n");
  printf("│          SIMULATION RESULTS         │\n");
  printf("├─────────────────────────────────────┤\n");
  printf("│                                     │\n");
  for (uint32_t i = 0; i < gs->sec_list_size; i++){
    printf("│  • [%-2u] : %-.2f                      │\n", i, gs->afk_list->values[i]);
  }
  printf("│                                     │\n");
  printf("│  Press Enter to continue...         │\n");
  printf("└─────────────────────────────────────┘\n");
}
