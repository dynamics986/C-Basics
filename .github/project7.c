/** data scope and address */
#include <stdio.h>

int x = 0;

void foo() {
   printf("Address 2: %p\n", &x);
}

int main(void) {
   int x = 0;
   printf("Address 1: %p\n", &x);
   if (x == 0) {
      int x = 1;
      foo();
      printf("Address 3: %p\n", &x);
   }
   return 0;
}
