#include <stdio.h>

int main() {
	int years = 3000;
	int i;
	
	for(i = 0; i < years; ++i){
		if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
			printf("The year %d is a leap year\n", i);
		}
	}
	return 0;
}