/** Selection Sort */

#include <stdio.h>

void SelectionSort(int input[], int size)
{
    int i, j, minPos, tmp;
    for (i = 0; i < 8; i++)
    { 
        // step1, do N-1 times

        // Locate the smallest element among input[i] … input[N-1],
        // and store the location of it in minPos. //step2
        minPos = i;
        for (j = i + 1; j < 8; j++)
            if (input[j] < input[minPos])
                minPos = j;

        // Swap input[i] with input[minPos] only if necessary //step3
        if (minPos != i)
        {
            tmp = input[i];
            input[i] = input[minPos];
            input[minPos] = tmp;
        }
    }
}

int main(void)
{
    int a[8] = {0};

    scanf("%d%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]);
    SelectionSort(a, 8);
    printf("%d %d %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]);
    return 0;
}