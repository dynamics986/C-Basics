/** Great Tool to Extract Codes on the Internet*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fin, *fout;   

    int ROWNUMBER;
    int N=0;
    printf("How many rows?");
    scanf("%d", &ROWNUMBER);
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if (fin == NULL || fout == NULL) {
        printf("Failed to open input or output file.\n");
        exit(1);
    }

    char str[1000];
    for (int i = 0; i < ROWNUMBER; i++) {
        fgets(str,sizeof(str),fin);
        str[0]= ' ';
        str[1]= ' ';
        N = (int) strlen(str);
        if (str[N-1] == '\n')
            str[N-1] = '\0';
        fprintf(fout, "%s\n", str);
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
