#include<iostream>
using namespace std;
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
int *fill_array(int n)
{
    int *arr=nullptr;
    arr=new int[n];
    cout<<"Enter the diagonal elements with a space"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
}
void show_diagonal_matrix(int *array,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<array[i]<<" ";
            }
            else
            {
                cout<<0<<" ";
            }
        }
        cout<<endl;    
    }
}
void triDiagonalMatrix(int n)
{    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-j<=1&&i-j>=-1)
            {                
                cout<<1<<" ";
                
                
            }
            else
            {
                cout<<0<<" ";
            }
            
        }
        cout<<endl;
    }
    
    
}
void upperTriagonalMatrix(int n)
{    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<=j)
            {                
                cout<<1<<" ";
                
                
            }
            else
            {
                cout<<0<<" ";
            }
            
        }
        cout<<endl;
    }
    
    
}
void lowerTriagonalMatrix(int n)
{    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=j)
            {                
                cout<<1<<" ";
                
                
            }
            else
            {
                cout<<0<<" ";
            }
            
        }
        cout<<endl;
    }
    
    
}
int **symmetricMatrix(int n)
{
    int element=0,k=0,prove=1;
    int **matrix=new int*[n];
    cout<<"Enter the elements of the matrix followed by a space"<<endl;
    for(int i=0;i<n;i++)
    {
        matrix[i]=new int[n];        
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]!=matrix[j][i])
            {
                prove=0;  
            }
            
        }
        if(!prove)
        {
            cout<<"Not a symmetric matrix"<<endl;
            break;
        }
    }
    printMatrix(matrix,n);
    if(prove==1)
    {
        cout<<"Symmetric matrix"<<endl;
    }
    
    
    

    return matrix;
    
}


int main()
{
    int choice,n=0,init_value=0,find=0;
    int *array=nullptr;
    int **matrix=nullptr;
    do
    {
        cout<<"--MENU---"<<endl;
        cout<<"1.Create Diagonal Element Matrix"<<endl;
        cout<<"2.Create Tri-diagonal Matrix."<<endl;
        cout<<"3.Create Lower triangular Matrix."<<endl;
        cout<<"4.Create Upper triangular Matrix."<<endl;
        cout<<"5.Create Symmetric Matrix"<<endl;
        cout<<"6.Exit"<<endl<<endl;
        
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            
                cout<<"Enter the Size of Matrix"<<endl;
                cin>>n;
                array=fill_array(n);
                show_diagonal_matrix(array,n);
                break;
        
                
                
            case 2:

                cout<<"Enter the Size of Matrix"<<endl;
                cin>>n;
                triDiagonalMatrix(n);
                break;

            case 3:    
                cout<<"Enter the Size of Matrix"<<endl;
                cin>>n;
                lowerTriagonalMatrix(n);
                break;
                
            case 4:
                cout<<"Enter the Size of Matrix"<<endl;
                cin>>n;
                upperTriagonalMatrix(n);
                break;
            case 5:
                cout<<"Enter the Size of Matrix"<<endl;
                cin>>n;                
                matrix=symmetricMatrix(n);
                break;

            default:                
                break;    

                
        }
 
    }while(choice!=6);
        
}