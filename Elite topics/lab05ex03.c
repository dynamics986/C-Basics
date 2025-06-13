/** Aliens come again */
#include <stdio.h>
#include <string.h>

int main(void){
    char str[60+1];
    int num[128];

    scanf("%s",str);
    int len = (int)strlen(str);

    for (int i=0;i<128;i++){
        num[i]=-1; // initialization
    }
    
    num[(int)str[0]]=1;
    int base=1;
    /** Pay Attention: We definitely 
     *  do not know what each digits mean */
    int NUM = 0;
    for (int i=1;i<len;i++){
        if (num[(int)str[i]]==-1){
            if (NUM==1){
                NUM++;
            }
            num[(int)str[i]] = NUM++;
            base++;
        }
    }
    printf("NUM=%d\n",NUM);
    printf("base=%d\n",base);

    long long result=0;
    if(base==1){
        for(int i=0;i<len;i++){
            result = result*2+num[(int)(str[i])];
        }
    }
    else {
        for (int i=0;i<len;i++){
            result = result*base+num[(int)str[i]];
        }
    }
    
    printf("%lld\n",result);
    return 0;
}

