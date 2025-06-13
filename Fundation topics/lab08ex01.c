/** character selection sort */
#include <stdio.h>

/* swap the content of the memory pointed by pointers a and b */
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

/* selection sort. 
   n is size of the array a.  */
void selection_sort(char a[], int n)
{
    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            if (a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}

int main()
{
    int n;
    char arr[100] = {0};

    printf("Array Size? ");
    scanf("%d", &n);

    // Read n array elements 
    // insert your code here
    for (int i = 0; i < n; i++){
        scanf(" %c", &arr[i]);
    }

    // sort the input array
    selection_sort(arr, n);

    // print the sorted array
    for (int i=0; i < n ; i++)
    {
        printf("%c", arr[i]);
        if (i != n-1) printf(" ");
    }
    printf("\n");

    return 0;
}