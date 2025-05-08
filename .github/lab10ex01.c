/** String processing */
#include <stdio.h>
#include <string.h>


int main(void) {
    // C view string as char array type
    // So it is the only way to declare a string in C
    char str[100];
    scanf("%s",str);
    int N = (int)strlen(str);
    for (int i = 0; i<= N-1; i++){
        if ('1' <=str[i] && str[i]<= '9'){
            str[i] = 106 - str[i] ;
        }
        if ('A'<=str[i] && str[i]<= 'Z'){
            str[i] = str[i] + 'a' - 'A';
            continue;
            // continue is irreplaceable here
        }
        if ('a'<=str[i] && str[i]<= 'z'){
            str[i] = str[i] - 'a' + 'A';
            continue;
        }
    }

    printf("%s\n",str);

    return 0;
}
