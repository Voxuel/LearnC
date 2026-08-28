#include <stdio.h>
#include <string.h>

int main() {
    char pass[100] = "this is a string";
    char enc[100];
    int key = 53;

    // XOR each character one by one
    for (int i = 0; i < strlen(pass); i++) {
        enc[i] = pass[i] ^ key;
    }
    enc[strlen(pass)] = '\0';  // null-terminate the string

    printf("Encrypted: %s\n", enc);

    // Decrypt by XORing again with the same key
    char dec[100];
    for (int i = 0; i < strlen(enc); i++) {
        dec[i] = enc[i] ^ key;
    }
    dec[strlen(enc)] = '\0';

    printf("Decrypted: %s\n", dec);

    return 0;
}