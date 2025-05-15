#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int globalVar = 10; // Static global variable

void display() {
    
    // printf("Global Variable: %d\n", globalVar);
    // globalVar = 100;
    // globalVar++;

    static int staticVar = 8;
    printf("Static Variable first: %d\n", staticVar);
    staticVar = 888;
    printf("Static Variable second: %d\n", staticVar);
    staticVar = 999;
    printf("Static Variable second: %d\n", staticVar);
}

int main() {
    display();
    display();
    display();
    return 0;
}

    

