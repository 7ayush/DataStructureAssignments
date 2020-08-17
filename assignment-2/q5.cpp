#include<iostream>
using namespace std;

int** fillMatrix(int m,int n)
{
    int **newMatrix=new int*[m];
    for(int i=0;i<m;i++)
    {
        newMatrix[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>newMatrix[i][j];
        }
    }
    return newMatrix;
}
int main()
{
    int m,n;
    cout<<"Enter the rows and the columns of the matrix;"<<endl;
    cin>>m>>n;
    cout<<"Fill the elements of the matrix"<<endl;
    int **matrix=fillMatrix(m,n);
    int t=0,b=m-1,l=0,r=n-1;
    int dir=0;
    while(l<=r&&t<=b)
    {
        if(dir==0)
        {
            for(int i=l;i<=r;i++)
            {
                cout<<matrix[t][i]<<",";
            }
            t++;
            dir=1;

        }
        if(dir==1)
        {
            for(int i=t;i<=b;i++)
            {
                cout<<matrix[i][r]<<",";
            }
            r--;
            dir=2;

        }
        if(dir==2)
        {
            for(int i=r;i>=l;i--)
            {
                cout<<matrix[b][i]<<",";
            }
            b--;
            dir=3;
        }
        if(dir==3)
        {
            for(int i=b;i>=t;i--)
            {
                cout<<matrix[i][l]<<",";
            }
            l++;
            dir=0;
        }
    }


    
}