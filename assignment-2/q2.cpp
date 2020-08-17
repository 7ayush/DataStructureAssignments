#include<iostream>
#include<algorithm>
using namespace std;
class sparse
{
    public:
    int row;
    int column;
    int value;

    sparse(int row,int column,int value)
    :row(row),column(column),value(value)
    {
    
    }   
    sparse()
    {

    }
};

int* fillArray(int n )
{
    int *array=nullptr;
    array=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    return array;
}
int maxValue(int *arr,int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;

}
sparse* fillSparse(int n)
{
    int row,column,value;
    sparse *sparse_array=new sparse[n];
    for(int i=0;i<n;i++)
    {
        cin>>row>>column>>value;
        sparse_array[i]=sparse(row,column,value);
    }
    return sparse_array;
}
int maxSparseValue(sparse *arr,int n)
{
    int max=arr[0].row;
    for(int i=1;i<n;i++)
    {
        if(max<arr[i].row)
        {
            max=arr[i].row;
        }
    }
    return max;

}
void sortSparse(sparse* sparse_array,int n)
{
    sparse temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(sparse_array[j].column>sparse_array[j+1].column)
            {
                temp=sparse_array[j];
                sparse_array[j]=sparse_array[j+1];
                sparse_array[j+1]=temp;
            }
        }
    }   
}
void displaySparse(sparse* array,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<array[i].column<<" "<<array[i].row<<" "<<array[i].value<<endl;
    }
    
}
int main()
{
    int choice,n1=0,n2=0,find=0;
    cout<<"Enter the number of non zero elements"<<endl;
    int *row1=nullptr;
    int *column1=nullptr;
    int *value1=nullptr;
    int *row2=nullptr;
    int *column2=nullptr;
    int *value2=nullptr;
    do
    {
        cout<<"--MENU---"<<endl;
        cout<<"1.Show the matrix"<<endl;
        cout<<"2.Transpose of matrix."<<endl;
        cout<<"3.Add a matrix"<<endl;
        cout<<"4.Multiply a matrix."<<endl;
        cout<<"5.Exit"<<endl<<endl;
        
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:{
                int rows=0,columns=0,found=0,k=0;
                cout<<"Enter the number of non zero elements the matrix"<<endl;
                cin>>n1;
                cout<<"Fill non zero rows of matrix"<<endl;
                row1=fillArray(n1);
                cout<<"Fill non zero columns of matrix"<<endl;
                column1=fillArray(n1);
                cout<<"Fill non zero values of matrix"<<endl;
                value1=fillArray(n1);
                rows=row1[n1-1]+1;
                columns=maxValue(column1,n1)+1;
                for(int i=0;i<rows;i++)
                {
                    for(int j=0;j<columns;j++)
                    {
                        
                        if(row1[k]==i&&column1[k]==j)
                        {
                            cout<<value1[k]<<" ";
                            k++;
                        }
                        else
                        {
                            cout<<0<<" ";
                        }

                    }
                    cout<<endl;
                }

                
                break;
        
            }
                
            case 2:{
                int rows=0,columns=0,found=0,k=0;
                cout<<"Enter the number of non zero elements the matrix"<<endl;
                cin>>n1;
                sparse *sparse_array=fillSparse(n1);
                cout<<endl;
                //displaySparse(sparse_array, n1);
                cout<<endl;
                sortSparse(sparse_array,n1); 
                //displaySparse(sparse_array, n1);
                rows=sparse_array[n1-1].column+1;
                cout<<"Rows are "<<rows<<endl;
                columns=maxSparseValue(sparse_array,n1)+1;
                cout<<"Columns are "<<columns<<endl;
                for(int i=0;i<rows;i++)
                {
                    for(int j=0;j<columns;j++)
                    {
                        if(sparse_array[k].column==i&&sparse_array[k].row==j)
                        {
                            cout<<sparse_array[k].value<<" ";
                            k++;
                        }
                        else
                        {
                            cout<<0<<" ";
                        }

                    }
                    cout<<endl;
                }
                delete[]sparse_array;
            }   
                
                break;

            case 3:
            {
                int rows1=0,columns1=0,found=0,k1=0,rows2=0,columns2=0,k2=0,value=0;
                bool flag1=false,flag2=false;
                cout<<"Enter the number of non zero elements the matrix1"<<endl;
                cin>>n1;
                cout<<"Fill non zero rows of matrix1"<<endl;
                row1=fillArray(n1);
                cout<<"Fill non zero columns of matrix1"<<endl;
                column1=fillArray(n1);
                cout<<"Fill non zero values of matrix1"<<endl;
                value1=fillArray(n1);
                cout<<"Enter the number of non zero elements the matrix2"<<endl;
                cin>>n2;
                cout<<"Fill non zero rows of matrix 2"<<endl;
                row2=fillArray(n2);
                cout<<"Fill non zero columns of matrix 2"<<endl;
                column2=fillArray(n2);
                cout<<"Fill non zero rows of matrix 2"<<endl;
                value2=fillArray(n2);
                
                rows1=row1[n1-1]+1;
                columns1=maxValue(column1,n1)+1;

                rows2=row2[n1-2]+1;
                columns2=maxValue(column2,n2)+1;
                if(rows1==rows2&&columns1==columns2)
                {
                    for(int i=0;i<rows1;i++)
                    {
                        
                        for(int j=0;j<columns1;j++)
                        {
                            value=0;       
                            if(row1[k1]==i&&column1[k1]==j)
                            {
                                value+=value1[k1];
                                k1++;
                            }
                            if(row2[k2]==i&&column2[k2]==j)
                            {
                            
                                value+=value2[k2];
                                k2++;                            
                                
                            }
                            
                            cout<<value<<" ";
                            
                        
                            

                        }
                        cout<<endl;
                    }
   
                }
                else
                {
                    cout<<"Invalid Addition"<<endl;
                }
                
                
                
                break;
            }    
            case 4:
            {
                int rows1=0,columns1=0,found=0,k1=0,rows2=0,columns2=0,k2=0,value=0,sum=0;
                bool flag1=false,flag2=false;
                cout<<"Enter the number of non zero elements the matrix1"<<endl;
                cin>>n1;
                cout<<"Fill non zero rows of matrix1"<<endl;
                row1=fillArray(n1);
                cout<<"Fill non zero columns of matrix1"<<endl;
                column1=fillArray(n1);
                cout<<"Fill non zero values of matrix1"<<endl;
                value1=fillArray(n1);
                cout<<"Enter the number of non zero elements the matrix2"<<endl;
                cin>>n2;
                cout<<"Fill non zero rows of matrix 2"<<endl;
                row2=fillArray(n2);
                cout<<"Fill non zero columns of matrix 2"<<endl;
                column2=fillArray(n2);
                cout<<"Fill non zero rows of matrix 2"<<endl;
                value2=fillArray(n2);
                
                rows1=row1[n1-1]+1;
                columns1=maxValue(column1,n1)+1;

                rows2=row2[n1-2]+1;
                columns2=maxValue(column2,n2)+1;
                if(columns1==rows2)
                {
                    for(int i=0;i<rows1;i++)
                    {
                        for(int j=0;j<columns2;j++)
                        {
                            sum=0;
                            flag1=false;
                            flag2=false;
                            for(int k=0;k<columns1;k++)
                            {
                                // +=matrix1[i][k]*matrix2[k][j];
                                if(row1[k1]==i&&column1[k1]==k)
                                {
                                    flag1=true;
                                    k1++;
                                }

                                if(row2[k2]==k&&column2[k2]==j)
                                {
                                    flag2=true;
                                    k2++;
                                }
                                if(flag1||flag2)
                                {
                                    sum+=value1[k1-1]*value2[k2-1];
                                
                                }
                            }
                            cout<<sum<<" ";
                        }
                        cout<<endl;
                    }
                }
                else
                {
                    cout<<"Not eligible for multiplication"<<endl;
                }
                
            }
                
                break;
           

            default:                
                break;    

                
        }
 
    }while(choice!=5);
    delete[] row1;
    delete[] column1;
    delete[] value1;
    delete[] row2;
    delete[] column2;
    delete[] value2;
    return 0;   
}



        