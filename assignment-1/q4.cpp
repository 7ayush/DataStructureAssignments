#include<iostream>
using namespace std;
#define row 3
#define column 3

int **getArray(int valueFlag=0)
{
    int element=0,k=0;
    int **arr=new int*[row];
    for(int i=0;i<row;i++)
    {
        arr[i]=new int[column];
        for(int j=0;j<column;j++)
        {
            if(valueFlag)
            {
                cout<<"Enter "<<k+1<<" element";
                cin>>element;    
                arr[i][j]=element;
                k++;
            }
            else
            {
                arr[i][j]=0;
            }
            
        }
    }
    return arr;
    
}
int **multiplyMatrix(int **matrix1,int **matrix2)
{
    int **matrixresult=getArray();
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            
            for(int k=0;k<column;k++)
            {
                matrixresult[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }    
    }
    return matrixresult;
    
}
void printMatrix(int **arr)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<arr[i][j]<<" ";
        
        }    
        cout<<endl;
    }
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int *create_array(int n)
{
    int values=0;
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>values;
        arr[i]=values;
    }
    return arr;
}
int *reverse_array(int arr[],int n)
{
    int *array=nullptr;
    array= new int[n];
    for(int i=0;i<n;i++)
    {
        array[i]=arr[n-i-1];
    }
    return array;
}
void transposeMatrix(int **matrix)
{
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            cout<<matrix[j][i]<<" ";
        }
        cout<<endl;
        
    }
    return ;
}
void deleteMatrix(int **matrix)
{
    for(int i=0;i<row;i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
int main()
{
    int choice=1,n=0,init_value=0,find=0;
    int m1=0,n1=0,m2=0,n2=0;
    int *array=nullptr;
    
    cout<<"--MENU---"<<endl;
    cout<<"1.Reverse the elements of an array"<<endl;
    cout<<"2.Find the matrix multiplication"<<endl;
    cout<<"3.Find the transpose of a matrix"<<endl<<endl;

    
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
            cout<<"Enter the number of Elements"<<endl;
            cin>>n;            
            array=create_array(n);
            array=reverse_array(array,n);
            display(array,n);
            break;
        case 2:
        {
            //if value flag means zero then it means that all elements of matrix will be initialised to zero
            cout<<"Enter Matrix 1 Elements"<<endl;
            int **matrix1=getArray(1);
            cout<<"Enter Matrix 2 Elements"<<endl;
            int **matrix2=getArray(1);
            
            // int matrix1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
            // int matrix2[3][3]={{1,4,9},{2,6,8},{3,5,7}};

            int **matrixresult=multiplyMatrix(matrix1,matrix2);
            printMatrix(matrixresult);
            
            deleteMatrix(matrix1);
            deleteMatrix(matrix2);
            deleteMatrix(matrixresult);            

            break;
        }

        case 3:
        {
           cout<<"Enter Matrix 1 Elements"<<endl;
            int **matrix1=getArray(1);
            
            // int matrix1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
            // int matrix2[3][3]={{1,4,9},{2,6,8},{3,5,7}};
            
            transposeMatrix(matrix1);
            deleteMatrix(matrix1); 
            break;
        }
        
            
           
    }
  
    delete[] array; 
}