#include<iostream>
using namespace std;
//Node becomes the element of the linkedlist
class Node
{
    public:
    int key;
    int data;
    Node *next;

    Node()
    {
        data=0;
        key=0;
        next=NULL;
    }
    Node(int key,int data)
    {
        this->key=key;
        this->data=data;
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
    Node* ifNodeExists(int k)
    {        
        Node *ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                return ptr;
            }
            ptr=ptr->next;
        }
        return ptr;
    }

    void prependNode(Node *n)
    {
        if(ifNodeExists(n->key)!=NULL)
        {
            cout<<"Node with the given key already exists"<<endl;
            return;
        }
        else
        {            
            n->next=head;
            head=n;
            cout<<"Node prepend done"<<endl;
        }
    }
    void appendNode(Node *n)
    {
        if(ifNodeExists(n->key)!=NULL)
        {
            cout<<"Node with the given key already exists"<<endl;
            return;
        }
        else
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
    }

    void insertNode(int k, Node *n)
    {
        Node *ptr=ifNodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No node with the given key "<<k<<endl;
        }
        else
        {
            if(ifNodeExists(n->key)!=NULL)
            {
                cout<<"The node with given key "<<n->key<<" already exists"<<endl;
            }
            else
            {   
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node inserted successfully"<<endl;
            }
            
        }
        

    }
    void deleteNode(int k)
    {
        if(head==NULL)
        {
            cout<<"Empty list. Can't delete"<<endl;            
        }
        if(head->key==k)
        {
            head=head->next;
            cout<<"Node deleted"<<endl;
        }
        else
        {
            Node *ptr=ifNodeExists(k);
            Node *ptrprev=head;
            while(ptrprev->next!=ptr)
            {
                ptrprev=ptrprev->next;
            }
            ptrprev->next=ptr->next;
            cout<<"Node deleted"<<endl;

        }
    }

    void printList()
    {
        Node * ptr=head;
        while(ptr!=NULL)
        {
            cout<<"["<<ptr->key<<","<<ptr->data<<"], ";
            ptr=ptr->next;
        }
        cout<<endl;
    }
   

    void deleteFirst()
    {
        if(head==NULL)
        {
            cout<<"Linked list is empty can't delete"<<endl;
            return;
        }
        if(head->next==NULL)
        {
            head=NULL;

        }
        else
        {
            head=head->next;
        }
        cout<<"The first element has been deleted"<<endl;
    }
    void deleteLast()
    {
        // Node* prevptr=head;
        // Node* nextptr=prevptr->next;
        // while(nextptr->next!=NULL&&nextptr!=NULL)
        // {
        //     nextptr=nextptr->next;
        //     prevptr=prevptr->next;
        // }
        
        if(head->next==NULL)
        {
            head=NULL;
            
        }
        else
        {
            Node *ptr=head;
            while((ptr->next)->next!=NULL)
            {
                ptr=ptr->next;

            }
            ptr->next=NULL;
            
        }
        cout<<"Node deleted"<<endl;


    }

    int searchAndShowPositionKey(int k)
    {
        int pos=0;
        Node* ptr=ifNodeExists(k);
        if(ptr==NULL)
        {
            cout<<"The Node does not exist "<<endl;
            return -1;
        }
        else
        {
            Node *itr=head;
            while(itr!=ptr)
            {
                itr=itr->next;
                pos++;
            }
            return pos;

        }

    }

};

int main()
{
    linkedList s;
    int option; 
    int key1,k1,data1;
    do
    {
        // cout<<"Enter a value as per the menu"<<endl;
        // cout<<"1. Append Node"<<endl;
        // cout<<"2. Prepend Node"<<endl;
        // cout<<"3. Insert Node"<<endl;
        // cout<<"4. Delete Node"<<endl;
        // cout<<"5. Update Node By Key"<<endl;
        // cout<<"6. Print"<<endl;
        // cout<<"7. Clear Screen"<<endl;

        cout<<"Enter a value as per the menu"<<endl;
        cout<<"1. Insertion at the beginning."<<endl;
        cout<<"2. Insertion at the end."<<endl;
        cout<<"3. Insertion after a given node"<<endl;
        cout<<"4. Deletion from the beginning."<<endl;
        cout<<"5. Deletion from the end."<<endl;
        cout<<"6. Deletion of a specific node"<<endl;
        cout<<"7. Search for a node and display its position from head."<<endl;
        cout<<"8. Display all the node values."<<endl;
        cout<<"9. Exit"<<endl;
        cin>>option;
        Node *n1=new Node();
        switch(option)
        {
            case 1:
                cout<<"Prepend Node Operation.\nEnter key and data of the Node to be prepended "<<endl;
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                s.prependNode(n1);                
                // cout<<n1->key<<"="<<n1->data<<endl;
                break;
            case 2:

                cout<<"Append Node Operation.\nEnter key and data of the Node to be appended "<<endl;
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                s.appendNode(n1);
                // cout<<n1->key<<"="<<n1->data<<endl;
                break;

            case 3:
                cout<<"Insert the node After Operation.\nEnter the key of existing node after which you want to Insert the new Node "<<endl;
                cin>>k1;
                cout<<"Enter the key and value of new node"<<endl;
                cin>>key1>>data1;
                n1->key=key1;
                n1->data=data1;
                s.insertNode(k1,n1);  
                break;  
            case 4:

                cout<<"First node to be deleted."<<endl;
                s.deleteFirst();
                break;
            case 5:
                cout<<"Last node to be deleted."<<endl;
                s.deleteLast();
                break;
                // cout<<"Update Node by Key operation.\nEnter the key and NEW Data to be updated"<<endl;
                // cin>>key1;
                // cin>>data1;
                // s.updateNode(key1,data1);
                // break;    

            case 6:
                cout<<"Delete node by key operation.\nEnter the key of the node to be deleted "<<endl;
                cin>>k1;                
                s.deleteNode(k1);  
                break;
                
            case 7:
                cout<<"Searching the Node by value and displaying its position"<<endl;
                cout<<"Enter the key of the node to be searched "<<endl;
                cin>>k1;
                cout<<"The position of the given node from head is "<<s.searchAndShowPositionKey(k1)<<endl;
                break;
                

            case 8:
                s.printList();
                break;
 
            default:
                break;

        }
    }while(option!=9);
 
    return 0;
}

