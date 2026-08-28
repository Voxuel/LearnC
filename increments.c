#include <stdio.h>
#include <string.h>

int full_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int compact_getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int main() {
    char buf1[100];
    char buf2[100];
    char input[] = "hello\nworld\n";

    /* Feed "hello\n" to full_getline */
    FILE *f1 = fmemopen(input, strlen(input), "r");
    stdin = f1;
    int r1 = full_getline(buf1, 100);
    fclose(f1);

    /* Feed "world\n" to compact_getline */
    FILE *f2 = fmemopen(input + 6, strlen(input + 6), "r");
    stdin = f2;
    int r2 = compact_getline(buf2, 100);
    fclose(f2);

    printf("full:    [%s] len=%d\n", buf1, r1);
    printf("compact: [%s] len=%d\n", buf2, r2);
    printf("match: %d\n", strcmp(buf1, buf2) == 0 && r1 == r2);

    return 0;
}