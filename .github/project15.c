/** Search Algorithm */
#include <stdio.h>

int findRange (int nums[], int N, int target, int* start, int* end){
    int same = -1, dif = -1;
    int result = 0;
    for (int i = 0; i < N; i++){
        if (nums[i] == target){
            same = i;
            result = 1;
        }
        else {
            dif = i;
        }
        if (same-dif == 1){
            *start = same;
        }
        if (same != -1)
            *end = same;
        if (result == 0){
            * start = -1;
            * end = -1;
        }
    }
    return result;
}

int main(){
    int nums1[] = {5,7,7,8,8,10};
    int nums2[] = {1,2,3,3,4,4,4};
    int nums3[] = {6,7,8,9,10};
    int nums4[] = {2,4,6,8,12};
    int nums5[] = {};
    int start = 0, end = 0,result = -100;
    result =findRange (nums1, 6, 8, &start, &end);
    printf("start=%d, end=%d, result=%d\n",start,end,result);
    result =findRange (nums2, 7, 4, &start, &end);
    printf("start=%d, end=%d, result=%d\n",start,end,result);
    result =findRange (nums3, 5, 10, &start, &end);
    printf("start=%d, end=%d, result=%d\n",start,end,result);
    result =findRange (nums4, 5, 7, &start, &end);
    printf("start=%d, end=%d, result=%d\n",start,end,result);
    result =findRange (nums5, 1, 3, &start, &end);
    printf("start=%d, end=%d, result=%d\n",start,end,result);
    return 0;
}
