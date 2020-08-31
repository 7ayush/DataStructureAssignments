#include<iostream>
#include<cmath>
using namespace std;
//Node becomes the element of the linkedlist
class Node
{
    public:
    int key;
    Node *next;

    Node()
    {
        
        key=0;
        next=NULL;
    }
    Node(int key)
    {
        this->key=key;
        next=NULL;
    }    
};
//contains elements that are attributes of linkedList like head
class linkedList
{

    public:
    Node *head;
    linkedList()
    {
        head=NULL;
    }
    linkedList(Node *n)
    {
        head=n;
    }
    void appendNode(Node *n)
    {
    
        if(head==NULL)         
        {
            head=n;
        }
        else
        {
            Node *ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=n;
            cout<<"Node appended"<<endl;
        }            
        
    }

   
    void printList()
    {
        Node * ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->key<<"-->";
            ptr=ptr->next;
        }
        cout<<endl;
    }
    
   
    void findMiddle()
    {
        int count=0,itr=1;
        Node* ptr=head;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            count++;
        }
        
        //cout<<"count is : "<<count<<endl;
        float val=0;
        ptr=head;
        if(count%2==0)
        {
            count/=2;
            while(itr<=count+1)
            {
                if(itr==count||itr==count+1)
                {
                    val+=ptr->key/2.0;
                    
                }
                ptr=ptr->next;
                itr++;
                
            }
            
        }
        else
        {
            count/=2;
            count++;
            while(itr<=count)
            {
                if(itr==count)
                {
                    val=ptr->key;
                }
                ptr=ptr->next;
                itr++;                
            }
            
        }
        cout<<val<<endl;
        
        
    }
//  ___ ___ ___ 
};

int main()
{
    int n,key,key1;
    linkedList s;
    cout<<"Enter the number of elements in the linked list"<<endl;
    cin>>n;
    Node **node=new Node*[n];
    for(int i=0;i<n;i++)
    {
        cin>>key1;
        node[i]=new Node(key1);
        s.appendNode(node[i]);
    }
    s.findMiddle();

    
    
    
    s.printList();
 
    return 0;
}

