#include<iostream>
#include<vector>
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
void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void saddlePoint(int **matrix,int m,int n)
{
    int smallestElement;
    int *largestElement=new int [n];
    int *indices=new int[n];
    int index;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        largestElement[i]=matrix[0][i];
        
        for(int j=0;j<m;j++)
        {
            if(largestElement[i]<=matrix[j][i])
            {
                largestElement[i]=matrix[j][i];
                indices[i]=j;
                //cout<<"Largest element is "<<largestElement[i];
            }
            // cout<<endl;

        }                
    }
    // cout<<endl;
    // printArray(largestElement,n);
    // cout<<endl;
    // printArray(indices,n);

    for(int i=0;i<n;i++)
    {
        bool found=false;
        smallestElement=largestElement[i];
        // cout<<smallestElement;
        for(int j=0;j<n;j++)
        {
            index=indices[i];
            if(smallestElement>matrix[index][j])
            {
                found=false;
                //cout<<smallestElement<<endl;
                break;
            }
            else
            {
                found=true;
                //cout<<smallestElement<<endl;
            }
        }
        if(found==true)
        {
            vec.push_back(smallestElement);
        }
    }

    if(vec.size()==0)
    {
        cout<<"Sorry No saddle point"<<endl;
    }
    else
    {
        for(int i=0;i<vec.size();i++)
        {
        cout<<vec[i]<<" ";

        }
    }
    

    

    /*
    1 2 3 4
    7 8 9 12
    7 8 9 12
    7 8 9 12 


    */

}

int main()
{
    int rows, columns;
    cout<<"Enter rows and columns with a space "<<endl;
    cin>>rows>>columns;
    int **matrix=createMatrix(rows, columns);
    saddlePoint(matrix,rows,columns);



}