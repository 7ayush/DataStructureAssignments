#include<iostream>
using namespace std;

int** fillMatrix(int n)
{
    int **matrix=new int*[n];
    int fill=1;
    for(int i=0;i<n;i++)
    {
        matrix[i]=new int[n];
        
    }
    int t=0,b=n-1,l=0,r=n-1;
    int dir=0;
    while(l<=r&&t<=b)
    {
        if(dir==0)
        {
            for(int i=l;i<=r;i++)
            {
                matrix[t][i]=fill;
                fill++;
            }
            t++;
            dir=1;

        }
        if(dir==1)
        {
            for(int i=t;i<=b;i++)
            {
                matrix[i][r]=fill;
                fill++;
            }
            r--;
            dir=2;

        }
        if(dir==2)
        {
            for(int i=r;i>=l;i--)
            {
                matrix[b][i]=fill;
                fill++;
            }
            b--;
            dir=3;
        }
        if(dir==3)
        {
            for(int i=b;i>=t;i--)
            {
                matrix[i][l]=fill;
                fill++;
            }
            l++;
            dir=0;
        }
    }

    return matrix;
}
void printMatrix(int **arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        
        }    
        cout<<endl;
    }
}

int main()
{
    int n;
    
    cout<<"Enter the size of the square matrix";
    cin>>n;
    int **matrix=fillMatrix(n);
    printMatrix(matrix,n);

}