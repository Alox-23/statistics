#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
       uint32_t* freq;
       float* rel_freq;	
       float total;
       uint32_t size;
} relative_freq_table;

relative_freq_table* create_rft(uint32_t size);
void destroy_rft(relative_freq_table* rft);
void print_rft(relative_freq_table* rft);
void calc_rel_rft(relative_freq_table* rft);
uint32_t get_freq_rft(relative_freq_table* rft, uint32_t index);
void set_freq_rft(relative_freq_table* rft, uint32_t index, uint32_t value);
void inc_freq_rft(relative_freq_table* rft, uint32_t index);
