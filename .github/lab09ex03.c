/** Reading a file
 * print the lines requested by the user, 
 * from start to end inclusively
 */
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int start, end;
    printf("Start? ");
    scanf("%d", & start);
    printf("End? ");
    scanf("%d", & end);

    FILE *fp;
    int times, content;

    fp = fopen("numbers.txt","r");

    int currentline = 1;

    while (fscanf(fp,"%d%d",&times,&content) != 1) {
        if (currentline >= start && currentline <= end){
            for (int i=0; i<times; i++){
                printf("%d ", content);
            }
            printf("\n");
        }
        else if (currentline > end) {
            break;
        }
        currentline++;
    }

    fclose(fp);
    return 0;
}