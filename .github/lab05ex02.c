/** ESTR Number: 153 = 1^3+5^3+3^3 */
#include<stdio.h>

int main(void){
    int len=0,b[22];
    unsigned long long a;
    scanf("%llu",&a);
    unsigned long long A=a;

    for(int j=0;j<=22;j++){
        if(a>0)
        {
            b[j]=a%10;
            a/=10;
            len++;
        }
    }
    int c=1,m;
    for(int n=1;n<66;n++){
        unsigned long long result=0;
        for(int i=0;i<len;i++){
            unsigned long long sum=1;
            for(m=1;m<=n;m++){
                sum*=b[i];
            }
            result+=sum;
        }
        if(result==A){
            printf("%d\n",m-1);
            return 0;
        }
    }
    printf("no");
    return 0;
}