#include "sim.h"

void run_simulation(global_state *gs){
  if (!gs) return;

  null_list(gs->afk_list);

  for (uint32_t k = 0; k < gs->secr_list->size; k++){
    float average_f_for_k = 0;
    for (uint32_t i = 0; i < gs->depth_per_k; i++){
      randomize_list(gs->secr_list);
      float f = traverse_list(gs->secr_list, k);
      average_f_for_k += f;
    }
    average_f_for_k = average_f_for_k / gs->depth_per_k * 100.0f;
    gs->afk_list->values[k] = average_f_for_k;
    if (k % 10 == 0) printf("Simulated %d, k-values...\n", k);
  }
}
