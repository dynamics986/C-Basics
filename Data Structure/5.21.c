#include <stdio.h>
#include <stdlib.h>

/* Find all Triplets with the product equal to a given number */

void Shellsort(int Arr[], int N){
	int j,Tmp;

	for(int increment = N / 2; increment > 0; increment /= 2)
		for(int i = increment; i < N; i++){
			Tmp = Arr[i];
			for(j = i; j >= increment; j -= increment)
				if(Tmp < Arr[j - increment])
					Arr[j] = Arr[j - increment];
				else
					break;
				Arr[j] = Tmp;
		}
}


int countTriplets(int arr[], int n, int m) {
    // the array is already sorted 
    int count = 0;
    // entries are n distinct integers
    
    // Handle the case where m == 0
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count += ((n-1) * (n-2)) / 2;
                return count;
            }
        }  
    }

    // If m != 0, use the two-pointer approach
    for (int i = 0; i < n - 2; i++) {
        if (arr[i] == 0) continue; // Skip zeros

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            // Skip zeros in the two-pointer approach
            if (arr[left] == 0) {
                left++;
                continue;
            }
            if (arr[right] == 0) {
                right--;
                continue;
            }

            int product = arr[i] * arr[left] * arr[right];

            if (product == m) {
                count++;
                left++;
                right--;
            }
            else if (product < m) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N); // Number of test cases

    while (N--) {
        int n, m; // note that m<10^5 
        scanf("%d %d", &n, &m);

        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]); // Read the array
        }

        Shellsort(arr, n); //sort the array first
        int result = countTriplets(arr, n, m);
        printf("%d\n", result);

        free(arr); // Free the allocated memory
    }

    return 0;
}