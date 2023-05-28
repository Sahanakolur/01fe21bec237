#include<stdio.h>
#include<stdlib.h>
main()
{
    FILE *fp;
    int r1,c1,r2,c2,a[10][10],b[10][10],c[10][10],sum;
    int i,j,k;
    fp=fopen("input.txt","r");
    fscanf(fp,"%d",&r1);
    fscanf(fp,"%d",&c1);
    fscanf(fp,"%d",&r2);
    fscanf(fp,"%d",&c2);
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
            fscanf(fp,"%d",&a[i][j]);
    }
    for(i=0;i<r2;i++)
    {
        for( j=0;j<c2;j++)
            fscanf(fp,"%d",&b[i][j]);
    }
    fclose(fp);
    fp=fopen("output.txt","w");
    fprintf(fp,"\n");
    if(r2==c1)
    {
        for( i=0;i<r1;i++)
        {
            for( j=0;j<c2;j++)
            {
                sum=0;
                for(k=0;k<r2;k++)
                    sum=sum+a[i][k]*b[k][j];
                c[i][j]=sum;
            }
        }
            for( i=0;i<r1;i++)
            {
                for(j=0;j<c2;j++)
                    fprintf(fp,"%d ",c[i][j]);
            }
    }
    else
        fprintf(fp,"Not possible");
    fclose(fp);
}
