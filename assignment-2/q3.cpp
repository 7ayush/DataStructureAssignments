#include<iostream>
using namespace std;

int **createMatrix(int m,int n)
{
    int **matrix=new int*[m];
    cout<<"Enter elements of matrix "<<endl;
    for(int i=0;i<m;i++)
    {
        matrix[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
            
        }
    }
    return matrix;

}
int *colsSum(int **matrix,int m,int n)//4 3
{
    int *sum=new int[m]; //4
    
    for(int i=0;i<m;i++)    //4 
    {               //0 0,1,2
        sum[i]=0;
        for(int j=0;j<n;j++) //3
        {
            sum[i]+=matrix[j][i]; //0 00 01 02
        }

    }
    return sum;
}

int *rowsSum(int **matrix,int m,int n)//4 3
{
    int *sum=new int[m]; //4
    
    for(int i=0;i<m;i++)    //4 
    {               //0 0,1,2
        sum[i]=0;
        for(int j=0;j<n;j++) //3
        {
            sum[i]+=matrix[i][j]; //0 00 01 02
        }

    }
    return sum;
}

void printMatrix(int **arr,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        
        }    
        cout<<endl;
    }
}

void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int rows, columns;
    cout<<"Enter rows and columns with a space "<<endl;
    cin>>rows>>columns;
    int **matrix=createMatrix(rows, columns);
    cout<<endl<<"The given matrix is "<<endl;
    printMatrix(matrix,rows,columns);
    
    int *rowSum=rowsSum(matrix,rows,columns);
    cout<<"The row sum is  ";
    printArray(rowSum,rows);

    cout<<endl;
    int *columnSum=colsSum(matrix,columns,rows);
    cout<<"The column sum is  ";
    printArray(columnSum,columns);

    return 0;
  



    
}