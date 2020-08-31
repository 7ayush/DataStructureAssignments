#include<iostream>
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
    Node * beforeNode(Node *n)
    {
        Node *n1=head;
        while(n1->next!=n)
        {
            n1=n1->next;
        }
        return n1;
    }
    
    void appendNode(Node *n)
    {
        if(head==NULL)         
        {
            
            head=n;
            //cout<<"Node appended"<<endl;
        }
        else
        {
            Node *ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=n;
            //cout<<"Node appended"<<endl;
        }            
    }

    int deleteAllNodes(int k)
    {
        int count=0;
        Node *ptr=head;

        Node *temp=NULL;
        if(head==NULL)
        {
            cout<<"Empty list. Can't delete"<<endl;            
            return 0;
        }
        
        else
        {            
            while(ptr!=NULL)   
            {
                if(ptr->key==k)
                {
                    count++;
                    if(head==ptr)
                    {
                        //cout<<"a."<<endl;
                        head=ptr->next;
                        ptr->next=NULL;
                        ptr=head; 
                                              
                    }
                    else
                    {
                        
                        temp=beforeNode(ptr);
                        //cout<<temp->key<<endl;
                        //cout<<"b."<<endl;
                        ptr=ptr->next;
                        temp->next=ptr;

                    }
                }
                else
                {
                    //cout<<"c."<<endl;
                    ptr=ptr->next;
                }
                
            }
            return count; 
        }
           
        
    }

    void printList()
    {
        Node * ptr=head;
        if(head==NULL)
        {
            cout<<"Empty List"<<endl;
        }
        while(ptr!=NULL)
        {
            cout<<ptr->key<<"-->";
            ptr=ptr->next;
        }
        cout<<endl;
    }

    

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
        s.printList();
        cout<<"Enter the key to be removed and counted"<<endl;
        cin>>key;
        cout<<"No of occurences are "<<s.deleteAllNodes(key)<<endl;
        s.printList();
    
}