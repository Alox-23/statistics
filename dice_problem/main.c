#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <stdbool.h>

//relative frequency table stuff
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

//relative frequency table stuff
relative_freq_table* create_rft(uint32_t size){
       	if (size <= 0){
        	printf("Invalid size when creating relative_freq_table\n");
               	return NULL;
       	}

       	relative_freq_table* rft;
       	rft = malloc(sizeof(relative_freq_table));
       	if (!rft){
        	printf("Error allocating rft\n");
        	return NULL;
       	}
	
	rft->size = size;
	rft->total = 0;

	rft->freq = calloc(size, sizeof(uint32_t));
	if (!rft->freq){
		printf("Failed to allocate rft->freq_tables\n");
		return NULL;
	}

	rft->rel_freq = calloc(size, sizeof(float));
	if (!rft->rel_freq){
		printf("Failed to allocate rft->freq_tables\n");
		return NULL;
	}

	return rft; //function worked
}

void destroy_rft(relative_freq_table* rft){
	if (!rft){
		printf("rft is NULL, cannot destroy\n");
		return;
	}

	free(rft->rel_freq);
	rft->rel_freq = NULL;
	free(rft->freq);
	rft->freq = NULL;
	free(rft);
	rft = NULL;
}

void calc_rel_rft(relative_freq_table* rft){
	if (!rft){
		printf("NULL rft pointer in cal_rel_rft\n");
		return;
	}

	for (int i = 0; i < rft->size; i++){
		rft->total += get_freq_rft(rft, i); //calculate the total (the denominator)
	}

	for (int i = 0; i < rft->size; i++){
		rft->rel_freq[i] = get_freq_rft(rft, i) / rft->total;
	}
}

void print_rft(relative_freq_table* rft){
	if (!rft){
		printf("rft is NULL, cannot print\n");
		return;
	}

	printf("\nRELATIVE FREQUENCY TABLE\n");
	printf("------------------------\n");
	printf("|%5s|%10s|%5s|\n", "Value", "Freq", "RFreq");
	printf("------------------------\n");

	for (int i = 0; i < rft->size; i++){
		char string_i[10];
		char string_freq[10];
		char string_rel_freq[10];

		sprintf(string_i, "%d", i);
		sprintf(string_freq, "%d", get_freq_rft(rft, i));
		sprintf(string_rel_freq, "%.3f", rft->rel_freq[i]);

		printf("|%5s|%10s|%5s|\n", string_i, string_freq, string_rel_freq);
	}
	printf("-----------------------\n");
}

uint32_t get_freq_rft(relative_freq_table* rft, uint32_t index){
	if (!rft){
		printf("invalid rft pointer during get\n");
		return UINT32_MAX;
	}
	if (index > rft->size){
		printf("index %d is out of bounds (0, %d)\n", index, rft->size);
		return UINT32_MAX;
	}
	return  rft->freq[index];
}

void set_freq_rft(relative_freq_table* rft, uint32_t index, uint32_t value){
	if (!rft){
		printf("invalid rft pointer during set\n");
		return;
	}
	if (index > rft->size){
		printf("index %d is out of bounds (0, %d)\n", index, rft->size);
		return;
	}

	rft->freq[index] = value;
}

void inc_freq_rft(relative_freq_table* rft, uint32_t index){
	if (!rft){
		printf("invalid rft pointer during set\n");
		return;
	}
	if (index > rft->size){
		printf("index %d is out of bounds (0, %d)\n", index, rft->size);
		return;
	}

	rft->freq[index] += 1;
}
