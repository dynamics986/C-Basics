#include <stdio.h>

int countLessOrEqual(int** matrix, int n, int mid) {
    int count = 0;
    int row = n - 1;
    int col = 0;
    
    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            count += row + 1;
            col++;
        } else {
            row--;
        }
    }
    return count;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int n = matrixSize;
    int left = matrix[0][0];
    int right = matrix[n-1][n-1];
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = countLessOrEqual(matrix, n, mid);
        
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// Helper function for testing
int main() {
    // Example 1
    int row1[] = {1, 5, 9};
    int row2[] = {10, 11, 13};
    int row3[] = {12, 13, 15};
    int* matrix1[] = {row1, row2, row3};
    int cols1[] = {3, 3, 3};
    
    printf("Example 1: %d\n", kthSmallest(matrix1, 3, cols1, 8)); // Output: 13
    
    // Example 2
    int row4[] = {-5};
    int* matrix2[] = {row4};
    int cols2[] = {1};
    
    printf("Example 2: %d\n", kthSmallest(matrix2, 1, cols2, 1)); // Output: -5
    
    return 0;
}