#include<bits/stdc++.h>
using namespace std;
class node 
{
    public:
    int data;
    node*next;
    node(int d) 
    {
        data = d;
        next = NULL;
    }
};
void insertattail(node*&head, int d) 
{
    if(head==NULL)
    {
		head = new node(d);
        return;
	}
	//else{
		node*temp = head;
		while(temp->next!=NULL)
        {
			temp = temp->next;
		}
		temp->next = new node(d);
        return;
}
void evenodd(node*head)                                 //No need to return node
{
    node *es=NULL;
    node *ee=NULL;
    node *os=NULL;
    node *oe=NULL;
    node *curr=head;                                     //ADDED
    //for(node*cur = head;cur!=NULL;cur=cur->next) 
    while(curr!=NULL)                                   //ADDED
    {
        if(curr->data%2==0) 
        {
            if(es==NULL)
            {
              es = curr;
              ee = curr;                                //Changed
            }
            else
            {
             ee->next = curr;
             ee = ee->next;
            }
        }
        else
        {
            if(os==NULL)
            {
              os = curr;
              oe = curr;                            //Changed
            }
            else
            {
             oe->next = curr;
             oe = oe->next;
            }
        }
        curr=curr->next;                                    //Added
    }

    if(os==NULL || es==NULL)                                //Changed
    {
        return;             
    }
    //os->next = os;
    oe->next = es;                                          //Changed
    ee->next=NULL;                                          //Changed
    head=os;                                                //Changed
}
void buildlist(node *&head)
{
  int N;
  cin>>N;
  int data;
  while(N>0)
  {
    cin>>data;
    insertattail(head,data);
    N--;
  }
}
void print(node*head) 
{
    //if(head==NULL){
      //  return;
    //}
    node*temp=head;
    while(temp!=NULL) 
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main() 
{
  node*head = NULL;  
  //int n;
  //cin>>n;
  //for(int i=0;i<n;i++){
    //  int d;
     // cin>>d;
      //insertattail(head,d);
   buildlist(head);                         //Added function to build the linked list
  evenodd(head);
 print(head);
}
