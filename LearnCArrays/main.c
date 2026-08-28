#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char from[], char to[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }
    if (max > 0) {
        printf("Longest line: %s", longest);
    }
    return 0;
}

int my_getline(char line[], int maxline) {
    int c, i;
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}