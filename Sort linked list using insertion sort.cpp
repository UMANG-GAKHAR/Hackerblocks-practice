#include<iostream>
using namespace std;
class node{
    public: int data;
            node* next;
            node(int data)
            {
                this->data=data;
                next=NULL;
            }
};
void inserAtTail(node* &head,int value)
{
    node* temp=new node(value);
    if(head==NULL)
     head=temp;
     else
     {
         node* trav=head;
         while(trav->next!=NULL)
         {
             trav=trav->next;
         }
         trav->next=temp;
     }
}
void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void InsertionSort(node* &head)
{
    if(head->next==NULL)
     return;
    node* front=head->next->next;
    node* curr=head->next;
    head->next=NULL;
    while(curr!=NULL)
    {
        node* temp=head;
        node* prev=NULL;
        while(temp->data<curr->data && temp!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        if(prev==NULL) // condition for insertion at head
         {
             head=curr;
         }
         else{   // condition for insertion at middle and end
             prev->next=curr;
         }
         curr->next=temp;
         curr=front;
         front=front->next;
    }
}
int main()
{
    node* head=NULL;
    int n,value;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        inserAtTail(head,value);
    }
    InsertionSort(head);
    print(head);
    return 0;
}
