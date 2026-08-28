#include <stdio.h>
#include <string.h>

int main(){
    char arr[10] = {'a','b','c','d','e','f','g','h','i','j'};
    char rev[11]; /* +1 for null terminator */
    int i;

    for(i = 0; i < 10; i++){
        rev[i] = arr[9 - i];
    }

    rev[10] = '\0';

    printf("%s\n", rev);

    return 0;
}