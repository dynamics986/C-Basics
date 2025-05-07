/**  Dynamics Memory Allocation */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, num, *ptr, *baseptr;

    printf("How many integers? ");
    scanf("%d", &num);

    baseptr = (int *)malloc( sizeof(int) * num );
    if ( baseptr == NULL )
        return 0;

    printf("Enter %d integers: ", num);
    ptr = baseptr;
    for (i = 0; i < num; i++) {
        scanf("%d", ptr);
        ptr++;
        printf("%p",ptr);
        printf("  %d\n",ptr);
    }
    
    printf("The numbers are: ");
    ptr = baseptr;
    for (i = 0; i < num; i++) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    free(baseptr);

    return 0;
}
