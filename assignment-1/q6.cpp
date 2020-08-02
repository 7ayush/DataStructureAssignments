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
void displayArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int noOfElements;
    cout<<"Enter the number of elements";
    cin>>noOfElements; 
    int *array=createArray(noOfElements);
    sortArray(array,noOfElements);
    displayArray(array,noOfElements);    
}