/** String Output */
#include <stdio.h>
#include <string.h>

int main(){
    
    char url[] = "MyCUHK";
    int i = 2;
    char *s = &url[6];
    printf("%d\n",url[i]);
    printf("%d\n", *s);
    printf("%d\n",url[5] );
    printf("%d\n",url[6] );

    /** String Length */
    char A[10] = "\\\n";
    char B[9] = {'1','b','\0','B'};
    printf("%d, %d\n",(int)strlen(A),(int)strlen(B));

    /** test string length */
    /** An array of size N can store a string 
     * containing up to N-1 characters. */
    // char array[7]={ 'A', 'B', 'C', 'a', 'D', 'E', '\0'};
    // int len = (int) strlen(array);
    // printf("%d",len);

    /** String Copy */
    char str1[100];
    char str2[100];
    strcpy(str1,"Foo"); //never write str1 = "Foo"
    strcpy(str2,str1); //never write str2 = str1
    printf("%s %s\n",str1,str2);

    char candy1[]  = {'A','B'};
    char candy[3];
    strcpy(candy , candy1);
    printf("%c %c [%c]\n",candy[0],candy[1],candy[2]);

    // char str[] = "\b>w<d/";
    // printf("%d\n", (int)strlen(str));
    // printf("%s\n", str);

    // char **s = "asdf";
    // int a[][] ={
    //     {}
    // }  
    // a[3] --> 
    // // *s ==> 'a'
    // // *(s+1) <==> s[1] == 's'
    // // s[2] <==> *(s + 2)
    
    // char *s = "%s";
    // char ss[] = "%s";
    // printf("%s\n", s);
    // // ss == 'x';
    // printf(s,s);
    // printf("\n%d\n", s==ss);

    // char c = '"',c1 = '\'';
    // printf("%c\n",c);
    // printf("%c\n",7);
    // printf("This is a warning!\a");

    return 0;
}