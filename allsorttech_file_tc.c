#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble_sort(int a[4],int m)
{
    int i,j,temp;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
            }
        }
    }
}

void selection_sort(int n,int a[n])
{
    int min,temp,i,j;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
               min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}
void merge(int arr[],int temp[],int left,int mid,int right)
{

    int i,left_end,size,temp_pos;
    left_end=mid-1;
    temp_pos=left;
    size=right-left+1;
    while(left<=left_end&&mid<=right)
    {
        if(arr[left]<=arr[mid])
        {
            temp[temp_pos]=arr[left];
            temp_pos++;
            left++;
        }
        else{
            temp[temp_pos]=arr[mid];
            temp_pos++;
            mid++;
        }
    }
    while(left<=left_end)
    {
         temp[temp_pos]=arr[left];
            temp_pos++;
            left++;
    }
       while(mid<=right)
    {
         temp[temp_pos]=arr[mid];
            temp_pos++;
            mid++;
    }
    for(i=0;i<=size;i++)
    {
        arr[right]=temp[right];
         right--;
    }
}

void mergeSort(int arr[],int temp[],int low,int high)
{

    if(low<high)
    {
         int mid=low+(high-low)/2;

        mergeSort(arr,temp,low,mid);
        mergeSort(arr,temp,mid+1,high);
        merge(arr,temp,low,mid+1,high);
    }
}
int main()
{
    int i,n;
    clock_t start,end;
    double total;
    start=clock();
    scanf("%d",&n);
    FILE *file = fopen("input.txt","w+");
    FILE *file1 = fopen("output.txt", "w");
    FILE *file2=fopen("time.txt","w");
    int a[n];
    for(i=0;i<n;i++)
       {
           a[i]=rand()%100;
       }
       for(i=0;i<n;i++)
       {
          fprintf(file,"%d ",a[i]);
       }
        for(i=0;i<n;i++)
        {
        fscanf(file,"%d",a[i]);
        }
    printf("\n");
    bubble_sort(a,n);
    fprintf(file1,"bubble_sort: ");
    for(i=0;i<n;i++)
       {
          fprintf(file1,"%d ",a[i]);
       }
       fprintf(file1,"\n");
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    fprintf(file2,"bubble_sort=%f\n ",total);
    start=clock();
    for(i=0;i<n;i++)
        {
            fscanf(file,"%d",a[i]);
        }
    printf("\n");
    selection_sort(n,a);
    fprintf(file1,"selection sort: ");
    for(i=0;i<n;i++)
       {
          fprintf(file1,"%d ",a[i]);
       }
    end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n");
    fprintf(file2,"selection_sort=%f\n",total);
    start=clock();
    for(i=0;i<n;i++)
        {
            fscanf(file,"%d",a[i]);
        }
    printf("\n");
    int temp[n];
    mergeSort(a,temp,0,n-1);
     fprintf(file1,"\nmerge_sort: ");
    for(i=0;i<n;i++)
       {
          fprintf(file1,"%d ",a[i]);
       }
        end=clock();
    total=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\n");
    fprintf(file2,"merge_sort=%f\n ",total);
    fclose(file);
    fclose(file1);
    fclose(file2);
    return 0;
}
