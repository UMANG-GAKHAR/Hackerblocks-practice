#include<iostream>
#include<cmath>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int d){
        data=d;
        next=NULL;
    }
};
void ins(node*&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new node(d);
    return;
}
void print(node*head){
    if(head==NULL){
        return;
    }
    while(head->next!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data<<endl;
    return;
}
int dataaa(node*head,node*head2,int d)
{
    node*temp=head;
    node*temp2=head2;
    while(d--)
    {
        temp=temp->next;
    }
    while(temp!=NULL && temp2!=NULL)  //change
    {
        if(temp->data==temp2->data)
        {
            return temp->data;
        }
        temp=temp->next;
        temp2=temp2->next;
    }
    return -1;

}

int main() 
{
    int n,m;
    node*head=NULL;
    node*head2=NULL;
    cin>>n;
    int n1=n;

    while(n--)
    {
        int d;
        cin>>d;
        ins(head,d);
    }
    cin>>m;
    int m1=m;
    int d=abs(n1-m1);
    //cout<<d;
    while(m--)
    {
        int d;
        cin>>d;
        ins(head2,d);
    }
    //print(head);
    //print(head2);
    if(n1>=m1)
    {
        cout<<dataaa(head,head2,d);
    }
    else
    {
        cout<<dataaa(head2,head,d);
    }
	return 0;
}
