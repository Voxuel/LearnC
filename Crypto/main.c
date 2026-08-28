#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chipers.h"
#include "utils.h"

int main(int argc, char **argv)
{
	int rc;
	char buff[100];
	
	rc = getLine("Enter plaintext: ", buff, sizeof(buff));
	if(rc == NO_INPUT){
		printf("No input given\n");
		return 1;
	}
	
	if(rc == TOO_LONG){
		printf("Too long input\n");
		return 1;
	}
	
	
	CipherInput inp;
	inp.plaintext = buff;
	inp.key = "abcdef";
	inp.len = strlen(buff);
	CipherInput *inpptr = &inp;
	
	ChiperResult result = run_xor(inpptr);
	
	if(result.data == NULL) {
		printf("Failed to allocate for chipertext");
		return 1;
	}
	
	printHex(result.data, result.len);
	
	CipherInput encInp;
	encInp.plaintext = result.data;
	encInp.key = "abcdef";
	encInp.len = result.len;
	CipherInput *encptr = &encInp;
	
	ChiperResult decrypted = run_xor(encptr);
	
	printf("Decrypted: %s", decrypted.data);
		
	free(result.data);
	free(decrypted.data);
	
	return 0;
}

ChiperResult run_xor(CipherInput *inp){
	int keylen = strlen(inp->key);
	int textlen = inp->len > 0 ? inp->len : strlen(inp->plaintext);
	char *buff = malloc(sizeof( char ) * (textlen + 1));
	if(buff == NULL){
		ChiperResult failed = {NULL, 0};
		return failed;
	}
	int i;
	for(i = 0; i < textlen; ++i){
		buff[i] = inp->plaintext[i] ^ inp->key[i % keylen];
	}
	
	ChiperResult cresult;
	cresult.data = buff;
	cresult.len = textlen;
		
	return cresult;
}