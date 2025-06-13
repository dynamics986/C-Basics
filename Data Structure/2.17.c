#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100000

/* Train Rearrangement using queue */
int main() {
    // input part
    int total; // total test cases
    scanf("%d", &total);
    
    int input[total][MAX];
    char output[total][3*MAX+1];
    int cart[total];
    // clock_t start = clock();
    for(int i = 0; i<total; i++) {
        scanf("%d", &cart[i]); // the total number of carts
        for(int j = 0; j < cart[i]; j++)
            scanf("%d", &input[i][j]);// entries in the carts
        int num = 1;   
        
        int current = 0;
        int start = 0, end = 0;
        // we define the end as that just to output from queue
        // start as the position just to input into the queue
        int queue[MAX];
        int possible = 1;
        // we only have three operations availble
        // stright through, enqueue, dequeue
        for(int j = 0; j < cart[i]; j++) {
            int result = input[i][j];
            if(start < end && queue[start] == result) {
                output[i][current++] = 'O';
                start++;
                continue;
            }
            while(num <= cart[i] && num != result) {
                queue[end++] = num;
                output[i][current++] = 'I';
                num++;
            }
            if(num > cart[i]) {
                if(!(start < end && queue[start] == result)) {
                    possible = 0;
                    break;
                }
            }
            if(num == result) {
                output[i][current++] = 'S';
                num++;
                continue;
            }
            if(start < end && queue[start] == result) {
                output[i][current++] = 'O';
                start++;
                continue;
            }
            possible = 0;
            break;
        }
        if( !possible || start < end) {
            output[i][0] = 'A';
            output[i][1] = '\0';
        }
        else output[i][current] = '\0';
    }
    // handling inpossible
    for (int i = 0; i < total; i++) {
        if (output[i][0] == 'A')
            printf("Impossible\n");
        else printf("%s\n", output[i]);
    }
    // clock_t end = clock();
    // double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    // printf("Time taken for the loop: %f seconds\n", time_taken);
    return 0;
}