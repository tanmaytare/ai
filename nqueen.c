#include<stdio.h>
#include<stdlib.h>

int isSafe(char** arr, int n , int row, int col)
{
    for(int i=0;i<n;i++)
    {
        if(arr[row][i] == 'Q')
        {
            return 0;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i][col] == 'Q')
        {
            return 0;
        }
    }

    int i = row;
    int j = col;

    while(i>=0 && j>=0)
    {
        if(arr[i][j]=='Q')
        {
            return 0;
        }

        i--;
        j--;
    }

    i = row;
    j = col;
    while(i<n && j< n)
    {
         if(arr[i][j]=='Q')
        {
            return 0;
        }

        i++;
        j++;
    }

    i = row;
    j = col;
    while(i>=0 && j< n)
    {
         if(arr[i][j]=='Q')
        {
            return 0;
        }

        i--;
        j++;
    }

    i = row;
    j = col;
    while(i<n && j>=0)
    {
         if(arr[i][j]=='Q')
        {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}

void nqueen(char** arr,int n, int row)
{
   if(row == n)
   {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c",arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
   }

   for(int i=0;i<n;i++)
   {
    if(isSafe(arr,n,row,i))
    {
        arr[row][i] = 'Q';
        nqueen(arr,n,row+1);
        arr[row][i] = '.';
    }
   }
}

int main()
{
    int n;
    printf("Enter size:");
    scanf("%d",&n);
    
    char** arr = (char **)malloc(n* sizeof(char *));
    for(int i=0;i<n;i++)
    {
        arr[i] = (char *)malloc(n* sizeof(char));
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = '.'; 
        }
    }

    nqueen(arr,n,0);
    return 0;
}