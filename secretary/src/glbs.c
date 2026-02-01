#include "glbs.h"

global_state* init_gs(uint32_t sec_list_size, uint32_t depth_per_k){
  global_state *gs = malloc(sizeof(global_state));
  if (!gs){
    printf("Global State - Error during init!\n");
    return NULL;
  }

  gs->sec_list_size = sec_list_size;
  gs->depth_per_k = depth_per_k;

  gs->user_input_size = 100;
  gs->user_input = malloc(sizeof(char) * gs->user_input_size);
  if(!gs->user_input){
    clean_gs(gs);
    return NULL;
  }

  gs->secr_list = init_list(sec_list_size);
  if (!gs->secr_list){
    clean_gs(gs);
    return NULL;
  }
  gs->fail_list = init_list(depth_per_k);
  if (!gs->fail_list){
    clean_gs(gs);
    return NULL;
  } 
  gs->afk_list = init_list(sec_list_size); // average-fail-per-k list (not "away from keyboard" !!)
  if (!gs->afk_list){
    clean_gs(gs);
    return NULL;
  }

  printf("Global State - Successfull init!\n");
  return gs;
}

int clean_gs(global_state* gs){
  if (!gs){
    printf("Global State - Error during clean!\n");
    return 1;
  }
  
  free(gs->user_input);
  gs->user_input = NULL;

  clean_list(gs->afk_list);
  gs->afk_list = NULL;
  clean_list(gs->fail_list);
  gs->fail_list = NULL;
  clean_list(gs->secr_list);
  gs->secr_list = NULL;
  
  free(gs);

  printf("Global State - Successfull clean!\n");
  return false;
}

void restart_gs(global_state** gs, uint32_t sec_list_size, uint32_t depth_per_k){
  printf("Global State - Restarting ...");

  clean_gs(*gs);
  *gs = init_gs(sec_list_size, depth_per_k);
}

char* safe_get(global_state *gs){
  if (!gs) return NULL;

  printf("> ");
  if (!fgets(gs->user_input, gs->user_input_size, stdin)) return NULL;

  size_t len = strlen(gs->user_input);
  
  if (len > 0 && gs->user_input[len-1] != '\n'){
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    gs->user_input[gs->user_input_size-1] = '\0';

    printf("Buffer was truncated!\n");
    return NULL;
  }

  if (len > 0){
    gs->user_input[len-1] = '\0';
  }

  return gs->user_input;
}
