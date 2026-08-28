#include <stdio.h>
#include <limits.h>

int main(){
	
	printf("Signed char: %d | %d \n", SCHAR_MIN, SCHAR_MAX);

	printf("Unsigned char: %d \n", UCHAR_MAX);

	printf("Signed short: %d | %d \n", SHRT_MIN, SHRT_MAX);

	printf("Unsigned short: %d \n", USHRT_MAX);

	printf("Signed int: %d | %d \n", INT_MIN, INT_MAX);

	printf("Unsigned Int: %u \n", UINT_MAX); / Important to use %u as display of unsigned int since %d converts it to signed

	
	return 0;
}