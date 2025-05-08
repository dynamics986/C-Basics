/** Reverse the content of each line of 
 *  input.txt, and save the results to output.txt.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *fin, *fout;
// Open input.txt using read mode, 
    fin = fopen("input.txt","r");

// open output.txt using write mode
    fout = fopen("output.txt","w");

    if (fin == NULL || fout == NULL){
        printf("Failed to open\n");
        exit(1);
    }

// Read a line from input.txt to a character array str.
    char str[256]; // Array to hold each line

// Read lines from input.txt until EOF
    while (fgets(str, 256, fin) != NULL) {
// Repeat the previous 3 steps until reaching the EOF.

        int len = (int) strlen(str);
// If the last character of str is newline character,
// change it to 0.
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }

// A loop to print the content of str reversely and write to output.txt
        for (int i = len - 1; i >= 0; i--) {
            fprintf(fout,"%c",str[i]); 
        }
        fprintf(fout,"\n");
    }

    // Close both files
    fclose(fin);
    fclose(fout);

    return 0;

}