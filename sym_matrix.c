#include<stdio.h>

void main()
{
    int a[100][100],n;
    int i,j,status=1;
    printf("Enter matrix size\n");
    scanf("%d",&n);
    printf("matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
           scanf("%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
    for(j=0;j<n;j++)
    {
        if (a[i][j]==a[j][i])
        {
          status=0;
        }
        else
        {
            status=1;
            break;
        }
    }
    }
    if(status==0)
    printf("symmetric\n");
    else
    printf("not symmetric\n");

}
