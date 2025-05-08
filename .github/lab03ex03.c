/** Happy Divisor */ 
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 3000001
/** Whether an integer only has prime divisors */
int main(void)
{
    int a,b;
    scanf("%d%d",&a,&b);

    int *A = (int*)malloc((b+1)*sizeof(int));
    unsigned int *B = (unsigned int *)malloc((b+1)*sizeof(unsigned int));

    for(int i=0;i<=b;i++)
    {
        A[i]=i;
    }

    for (int i=2;i*i<=b;i++)
    {
        if (A[i]==i)
        {
            for(int j=i * i;j<= b;j+= i)
            {
                if (A[j]==j)
                {
                    A[j]=i;
                }
            }
        }
    }

    B[1]=1;
    for (int N=2;N<=b;N++)
    {
        int y=N;
        unsigned int p=1;
        int m=0;

        while(y>1)
        {
            int x=A[y];

            if (x!=m)
            {
                p*=x;
                m=x;
            }

            while(y%x==0)
            {
                y/=x;
            }
        }
        B[N]=p;
    }

    int count=0;
    for (int N=a;N<=b;N++)
    {
        if (B[N]<N && N%B[N]==0)
        {
            count++;
        }
    }

    printf("%d\n",count);

    free(A);
    free(B);

    return 0;
}
