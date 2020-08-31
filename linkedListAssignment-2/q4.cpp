#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node()
    {
        data=0;
        next=NULL;
    }
    Node(int data)
    {
        this->data=data;
    }

};
class linkedList
{

public:
    Node* head;
    linkedList()
    {
        head=NULL;
    }
    linkedList(Node *n)
    {
        head=n;
    }
    
    void appendNode(Node* n)
    {
        Node* ptr;
        if(head==NULL)
        {
            head=n;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=n;

        }
    }
    void reverseList()
    {
        Node* prevptr=NULL;
        Node* currentptr=head;
        Node* nextptr;
        while(currentptr!=NULL)
        {   
            nextptr=currentptr->next;
            currentptr->next=prevptr;
            prevptr=currentptr;
            currentptr=nextptr;
            
        }
        head=prevptr;
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
            cout<<ptr->data<<"-->";
            ptr=ptr->next;
        }
        cout<<endl;
    }    
};



int main()
{
    int num=10;
    linkedList ll;
    Node** n=new Node*[num];
    for(int i=1;i<=num;i++)
    {
        n[i-1]=new Node(i);
        ll.appendNode(n[i-1]);
    }
    ll.printList();
    cout<<endl;
    ll.reverseList();
    ll.printList();
    cout<<endl;


}