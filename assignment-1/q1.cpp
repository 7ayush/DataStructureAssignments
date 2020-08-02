#include<iostream>
using namespace std;

int search_element(int arr[],int n)
{
    int search=0,found=0;
    cout<<"Enter the element to search"<<endl;
    cin>>search;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==search)
        {
            cout<<"Element found at position "<<i+1<<endl;
            found=1;
        }

    }
    if(found==0)
    {
        cout<<"Not Found"<<endl;
    }
    return 0;

}
int *create_array(int n,int initial_value)
{
    int *arr=nullptr;
    arr=new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=initial_value;
    }
    return arr;
}

int *delete_element(int arr[],int n)
{
    int position;
    cout<<"Enter Position"<<endl;
    cin>>position;
    for(int i=position-1;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    return arr;
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int *insert_element(int array[],int n)
{
    int position,value;
    cout<<"Enter position"<<endl;
    cin>>position;
    cout<<"Enter value"<<endl;
    cin>>value;
    //n++;
    for(int i=n;i>=position;i--)
    {
        array[i]=array[i-1];

    }
    array[position-1]=value;
    return array;
}
int main()
{
    

    int choice=1,n=0,init_value=0,find=0;
    int *array=nullptr;
    do{
        cout<<"--MENU---"<<endl;
        cout<<"1.CREATE"<<endl;
        cout<<"2.DISPLAY"<<endl;
        cout<<"3.INSERT"<<endl;
        cout<<"4.DELETE"<<endl;
        cout<<"5.SEARCH"<<endl;
        cout<<"6.EXIT"<<endl<<endl;

        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            
                cout<<"Enter the number of Elements"<<endl;
                cin>>n;
                cout<<"Enter the initial value"<<endl;
                cin>>init_value;
                array=create_array(n,init_value);
                break;
        
                
                
            case 2:
            
                display(array,n);
                break;

            case 3:    
                insert_element(array,n);
                n++;
                display(array,n);
                break;
                
            case 4:
                delete_element(array,n);
                n--;
                display(array,n);
                break;

            case 5:
                search_element(array,n);
                break;

            default:                
                break;    

                
        }
    }while(choice!=6);
    delete[] array;
}