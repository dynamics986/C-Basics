#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main(void){
    int64_t i;
    printf("%s, %s\n", SCNd64, PRId64);
    scanf("%"SCNd64, &i);
    printf("%"PRId64"\n", i);
    return 0;
}
