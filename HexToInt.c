#include <stdio.h>
#include <stdlib.h>


int htoi(const char *inp);

int main() {
	const char *inp = "0x12345";
	int result = htoi(inp);
	printf("Result: %d\n", result);
	return 0;
}

int htoi(const char *inp) {
	return (int)strtol(inp, NULL, 0);
}