/** output testing */
#include <stdio.h>
#include <math.h>

int main(){
    int x = 3;
    /** Calculating order of ++i, i++ */
     printf("%d\n", x+3);//x == 6
     printf("%d\n", x);//x == 3
     printf("%d\n", x += 3);//x == 6
     printf("%d\n", x);//x == 6
     printf("%d\n", 1 || x ++);//x == 1
     printf("%d\n", x);//x == 6
     printf("%d\n", ++x);//x == 7
     printf("%d\n", x);//x == 7

    /** Operation order of ++i, i++ */
    // int y = 1;
    // printf("%d\n", (x---y)); // 3-1=2
    // printf("%d\n", x); // x == 2
    // x = 3;
    // printf("%d\n", (x-(--y))); // 3-0=3

    /** output testing */
    // printf("%c\n",64);
    // printf("@\n");
    // printf("%f\n",7.0+ .958);
    // printf("%f\n",3e6); // 3e6 has type 'double'
    // printf("%.0f\n",3e0);
    printf("%f\n",pow(2+3,2)); //pow(2+3, 2)) has type 'double'
    
    float f = .1;
    printf("%d\n", f == .1f);
    /** output testing */
    // int i=10,j=5,k=-1;
    // printf("m = %d\n",i-=-j);
    // printf("n = %d\n",i+=+j);
    // printf("j mod2 =%d\n",j % 2);
    // printf("k mod2 =%d\n",k % 2);

    /** output testing */
    // printf("\\\n");
    // printf("[%c\\n]",92);
    // //printf("\%c\n",92);
    // printf("[\%c\n]",92);
    // printf("[\\%cn]",92);

    // int x,y;
    // scanf("%d %d",&x,&y);

    /** output testing */
    // x=x+y; 
    // y=x-y; 
    // x=x-y;
    // printf("%d %d\n",x,y);
    // printf("%d\n",0100);
    
    return 0;
}