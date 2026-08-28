#include <stdio.h>

int main() {
	
	/* Bit shifting can be explained like following
	 * n << k equals n * 2^k
	 * while n >> k equals n / 2^k
	 * When it comes to ^ (XOR) we compare the bits of both sides and sets to 1 only if the values at the index are different
	 * eg, 1010 ^ 0010 = 1000
	 * This should not be confused with "The power of" which is part of math.pow()
 */
	
	int n = 10;
	int m = n >> 2;
	int p = n ^ 2;
	char pass[100];
	
	printf("%d\n", m);
	printf("%d\n", p);
	return 0;
}