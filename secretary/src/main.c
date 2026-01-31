#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "secr.h"

int main(){
	srand(time(NULL));

  secr *secr_data = init_secr(100);

  clean_secr(secr_data);
}
