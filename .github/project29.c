#include <stdio.h>

int main(void){
    // char str[32];
    // fgets(str, 32, stdin);
    // printf("stdout: %s", str); // stdout
    // fprintf(stderr, "stderr: %s", str);

    int m;
    char s[256];
    printf("Please type an integer for one line and a string for the other line:\n");
    scanf("%d", &m);
    //gets(s);
    fgets(s,256,stdin);
    printf("You typed:\n");
    printf("%d\n", m);
    printf("%s", s);

    return 0;
}
