/** C Program to tell whether an IP address is correct */
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){
    /** Good practice for char array, int array and loops */
    char s[21],a[4][4];
    int n=0,m=0,A[4]={0};
    fgets(s,sizeof(s),stdin);

    for(int i=0;i<strlen(s);i++){
        if(!isdigit(s[i])){
            a[n][m]='\0';
            n++;
            m=0;
        }
        else 
            a[n][m++]=s[i];
    }

    for(int i=0;i<strlen(a[0]);i++)
        A[0]=A[0]*10+(a[0][i]-48); 
    for(int i=0;i<strlen(a[1]);i++)
        A[1]=A[1]*10+(a[1][i]-48);
    for(int i=0;i<strlen(a[2]);i++)
        A[2]=A[2]*10+(a[2][i]-48);
    for(int i=0;i<strlen(a[3]);i++)
        A[3]=A[3]*10+(a[3][i]-48);

    // printf("%d %d %d %d\n",A[0],A[1],A[2],A[3]);
    if((A[0]>=0&&A[0]<=255)&&(A[1]>=0&&A[1]<=255)&&(A[2]>=0&&A[2]<=255)&&(A[3]>=0&&A[3]<=255))
        printf("yes\n");
    else 
        printf("no\n");
    return 0;
}
