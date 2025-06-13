#include <stdio.h>
#include <string.h>

int main(void){
    /** Multi level Pointer */
    int a = 10, y = 111;
    // int * p = &a;
    // int ** q = &p;
    // int *** r = &q;
    // printf("x=%d *p=%d p=%p\n",a, *p, p);
    // printf("p=%p *q=%p q=%p\n",p, *q, q);
    // printf("q=%p *r=%p r=%p\n",q, *r, r);

    /** p->q->x */
    int** p, x = 10;
    int* q;
    q = &x;
    q = *p ; // *p=0x1f66700d0 p=0x1f66700a0 
    // *p = q ; // bus error
    // *p = &x; // bus error
    printf("x=%d *p=%p p=%p\n",x, *p, p);
    printf("q=%d q=%p",q,q); // q=-161021744 q=0x1f66700d0
    
    /** Copying by Reference and by Value */
    // int foo1 = 5, bar2 = 10;
    // int *p1, *p2;
    // p1 = &foo1;
    // p2 = &bar2;
    // *p1 = *p2; // Copying the value at an address
    // printf("%d %d", foo1,bar2);

    // int foo3 = 5, bar4 = 10;
    // int *p3, *p4;
    // p3 = &foo3;
    // p4 = &bar4;
    // p3 = p4; // Copying an address
    // printf("%d %d", foo3,bar4);

    return 0;
}
