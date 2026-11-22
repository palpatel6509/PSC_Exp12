#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char ch;

    /* OPEN FILE IN WRITE MODE */
    fp = fopen("chars.txt","w");
    if( fp == NULL )
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter Characters(Press enter to stop):\n");
    while((ch = getchar()) != '\n')
    {
        fputc(ch,fp);
    }
    fclose(fp);

    /* REOPEN FILE IN READ MODE */
    fp = fopen("chars.txt" , "r");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("\nContent read from file:\n");
    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    printf("\n");

    fclose(fp);
    return 0;
}