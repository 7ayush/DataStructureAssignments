#include<iostream>
using namespace std;

int main()
{
    int arr[] ={1,2,3,5,6,7,8,9,10,90,95,98,99,100,110,115,120,130,140,160,170}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    int num,mid=0;
    cin>>num;
    int l=0,r=n-1;
    int i=1;
    while(l!=r)
    {
        
        mid=(l+r)/2;
        //cout<<arr[mid]<<" ";
        if(num==arr[mid])
        {
            cout<<"No. "<<arr[mid]<<" found at "<<mid+1<<endl;
            break;
        }
        else if(num<arr[mid])
        {
            r=mid;
        }
        else
        {
            l=mid;
        }
        i++;
        
        
    }
    cout<<"Iterations are "<<i<<endl;

}