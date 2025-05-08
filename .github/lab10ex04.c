/** scanf and fgets comparsion */
#include <stdio.h>

void scanf_test(){
    char inputArray[20] = {0};
    printf("User input: ");
    scanf("%s", inputArray);
    for (int i=0; i<= 19; i++){
        printf("%c ",inputArray[i]);
    }
    printf("\n");
    for (int i=0; i<= 19; i++){
        printf("%d ",inputArray[i]);
    }
    printf("\n");
    printf("%s\n", inputArray);
}

void fgets_test(){
    char inputArray[20] = {0};
    printf("User input: ");
    fgets(inputArray,20,stdin);
    for (int i=0; i<= 19; i++){
        printf("%d ",inputArray[i]);
    }
    // ASCII 10 is the new line character
    printf("\n");
    printf("%s\n", inputArray);
}

int main(void) {
    scanf_test();
     // fgets_test();
    return 0;
}