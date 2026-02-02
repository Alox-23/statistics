#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "glbs.h"

#define GRAPH_WIDTH 60
#define GRAPH_HEIGHT 15

void print_clear();
void print_main();
void print_bye();
void print_simulation_start(global_state *gs);
void print_settings_menu();
void handle_settings_change(global_state *gs);
void print_help_info(global_state *gs);
void print_invalid_choice();
void print_simulation_results(global_state *gs);

#endif
