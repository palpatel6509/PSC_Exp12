#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    int n,num,i,sum = 0;
    float avg;

    /* OPEN FILE IN READ MODE */
    fp = fopen("numbers.txt","w");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter the count of numbers:");
    scanf("%d",&n);

    printf("Enter %d integer numbers:\n",n);
    for( i = 0; i < n; i++ )
    {
        scanf("%d",&num);
        fprintf(fp, "%d\n",num);
    }
    fclose(fp);

    /* REOPEN FILE IN READ MODE */
    fp = fopen("numbers.txt","r");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    while(fscanf(fp, "%d",&num) != EOF)
    {
        sum += num;
    }
    fclose(fp);

    if( n > 0)
    {
        avg = (float)sum / n;
        printf("\nSum = %d\n",sum);
        printf("Average = %.2f\n",avg);
    }

    else
    {
        printf("\nNo numbers Entered.\n");
    }

    return 0;
}