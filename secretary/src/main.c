#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

#include "relfreq.h"

uint8_t roll_dice(){
 return rand() % 6 + 1;
}

//examples
void regular_dice_throw(){
	relative_freq_table* rft = create_rft(7);
	uint32_t n_dice;
	printf("Enter N of dice throws: ");
	scanf("%d", &n_dice);

	 //gon time the time taken to do n_dice iterations(each iteration = a couple memory moves and rand() call)
	clock_t start, end;
	double cpu_time_used;

	printf("\n");
	start = clock();
	for (uint32_t i = 0; i < n_dice; i++){
		if (i % 10000000 == 0) printf("Completed %d throws...\n", i);
		inc_freq_rft(rft, roll_dice());
	}

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	calc_rel_rft(rft);
	print_rft(rft);

	printf("\nTime taken: %f seconds\n", cpu_time_used);
	  
	destroy_rft(rft);
}

void sum_dice_throw(){
	relative_freq_table* rft = create_rft(6);
	uint32_t n_dice;
	printf("Enter N of dice throws: ");
	scanf("%d", &n_dice);

	//gon time the time taken to do n_dice iterations(each iteration = a couple memory moves and rand() call)
	clock_t start, end;
	double cpu_time_used;

	printf("\n");
	start = clock();
	for (uint32_t i = 0; i < n_dice; i++){
		if (i % 10000000 == 0) printf("Completed %d throws...\n", i);
		
		uint8_t d1 = roll_dice();
		uint8_t d2 = roll_dice();
		int abs_val = d1 - d2;
		if (abs_val < 0) abs_val *= -1;
		inc_freq_rft(rft, abs_val);
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

	calc_rel_rft(rft);
	print_rft(rft);
	 
	printf("\nTime taken: %f seconds\n", cpu_time_used);
	  
	destroy_rft(rft);
}

int main(){
	srand(time(NULL)); //current time is used as seed
	
	while (true){
		int mode;
		printf("Pick if you want regular(0) or abs-val(1) of exit(2): ");
		scanf("%d", &mode);
		if (mode == 0) regular_dice_throw();
		else if (mode == 1) sum_dice_throw();
		else if (mode == 2) break;
	}
	
	return 0;
}
