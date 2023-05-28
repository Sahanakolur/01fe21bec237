#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    FILE *fptr1,*fptr2;
    char name[100],key[100],temp[100],n;
    printf("Enter the world to be replaced:\n");
    scanf("%s",name);
    printf("enter the key: ");
    scanf("%s",key);
    fptr1=fopen("input.txt","r");
    fptr2=fopen("output.txt","a");
    while(!feof(fptr1))
    {
        fscanf(fptr1,"%s",temp);
        if(strcmp(temp,name)==0)
        {
            fprintf(fptr2,"%s ",key);

        }
        else
        {
            fprintf(fptr2,"%s ",temp);

        }
    }
    fclose(fptr1);
    fclose(fptr2);
}
