/** Shift Vowels */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_vowel(char c) {
    return strchr("aeiouAEIOU", c) != NULL;
}

// Function to perform circular shift on vowels
void circular_shift(char *vowels, int count, int k) {
    if (count == 0) return;

    // Normalize k to be within the bounds of the number of vowels
    k = (k%count+count)%count;
    if (k == 0) return;

    // Perform the shift using a temporary buffer
    char temp[count];
    
    memcpy(temp, vowels + k, count - k);
    //printf("%s\n",vowels);
    memmove(temp + count - k, vowels, k);
    memcpy(vowels, temp, count);
}

int main() {
    char s[201];
    int k;
    if (scanf("%200s", s) != 1 || scanf("%d", &k) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Extract vowels and their locations
    char vowels[201] = "";
    int indexs[201];
    int v_count = 0;

    for (int i = 0; s[i]; ++i) {
        if (is_vowel(s[i])) {
            vowels[v_count] = s[i];
            indexs[v_count++] = i;
        }
    }

    // Perform circular shift on vowels
    circular_shift(vowels, v_count, k);

    // Reconstruct the string with shifted vowels
    for (int i = 0; i < v_count; ++i) {
        s[indexs[i]] = vowels[i];
    }

    printf("%s\n", s);

    return 0;
}