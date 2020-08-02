#include<iostream>
using namespace std;

int *createArray(int n)
{
    int *array=nullptr;
    array=new int[n];
    cout<<"Enter "<<n<<" Elements followed by space"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    return array;
}
int *sortArray(int *arr,int n)
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
void displayArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int findMissingElement(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        if((arr[i+1]-arr[i])!=1)
        {
            return (arr[i]+1);
        }
        
    }
    return (arr[n-1]+1);
}

int main()
{
    int noOfElements;
    cout<<"Enter the number of elements";
    cin>>noOfElements; 
    int *array=createArray(noOfElements);
    sortArray(array,noOfElements);

    displayArray(array,noOfElements);    
    cout<<endl<<findMissingElement(array,noOfElements)<<endl;

}