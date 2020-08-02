#include<iostream>
using namespace std;
bool found(int arr[],int element,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            return true;
        }
    }
    return false;
}
int *updateArray(int arr[],int n)
{
    int k=0;
    int *array=nullptr;
    array=new int[n];
    for(int i=0;i<n;i++)
    {
        array[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        //cout<<found(array,arr[i],n)<<endl;
        if(!found(array,arr[i],n))
        {
            array[k]=arr[i];
            k++;
        }
    
    }
    
    return array;
    
}


int* createArray(int n)
{
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
}
void displayArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void displayUpdatedArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            cout<<arr[i]<<" ";    
        }
        
    }
    cout<<endl;
}

int *sortArray(int arr[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>=arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }
    return arr;
    
}

int main()
{
    int n;
    cout<<"Enter no. of elements in the array"<<endl;
    cin>>n;
    int *array=nullptr;
    cout<<"Fill the array elements"<<endl;
    array=createArray(n);
    displayArray(array,n);
    cout<<"Sorted array is "<<endl;
    sortArray(array,n);
    displayArray(array,n);
    array=updateArray(array,n);
    cout<<"Unique array is "<<endl;
    displayUpdatedArray(array,n);
    
    
    
    
    
}