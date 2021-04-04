#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int data;
	node * next;
	node(int d)
	{
		data=d;
		next=NULL;
	}
};
void print (node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}

int length (node*head)
{
	int len=0;
	while(head!=NULL)
	{
		head=head->next;
		len+=1;
	}
	return len;
}
void insertathead(node *&head,int data)
{
	node * n= new node(data);
	n->next=head;
	head=n;
}

void insertattail(node *&head,int data)
{
	if(head==NULL){
		head= new node(data);
		return;
	}

	node * temp=head;
	 while(temp->next!=NULL)
	 	temp=temp->next;
	temp->next=new node (data);
	return;
}

bool search(node *head,int key)
{
	if(head==NULL)
		return false;
	if(head->data==key)
		return true;
	else 
		return search(head->next,key);
}
void deletion(node *&head,int key)
{
	if(head==NULL)
		return;

	node * temp = head;
	node * pre = NULL;
	while(temp !=NULL&& temp->data!=key)
	{
		pre=temp;
		temp=temp->next;
	}
	if(temp==NULL)
		return;
	else if(temp==head)
		head=head->next;
	else
		pre->next=temp->next;
	delete temp;
}
void deleteathead(node *&head)
{
	if(head==NULL)
		return;
	node *temp=head;
	head=head->next;
	delete temp;
}

void deleteattail(node *head)
{
	if(head==NULL)
		return;
	node *temp=head;
	node * pre = NULL;

	while(temp->next!=NULL)
	{
		pre =temp;
		temp=temp->next;
	}
	pre->next=NULL;
	delete temp;	
}

void insertlist(node *& head)  //inputs LL ...stops at -1
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertattail(head,data);
		cin>>data;
	}
}

void insertlist(node *& head,int s)  //inputs LL ...taking s as the size of list
{
	int data,i=0;
	cin>>data;
	while(i<s)
	{
		insertattail(head,data);
		cin>>data;
		i++;
	}
}

istream & operator>>(istream & is,node *&head)    // operator overloading
{                                                 //cin>>head1>>head2 will do the work of insertlist(head1) and insertlist(head2)
	insertlist(head);
	return is;
}
ostream & operator<<(ostream & os,node *&head)    // cout<<head1<<head2 will do the work of print(head1) and print(head2)
{
	print(head);
	return os;
}


node* searchx(node *head,int key)
{
	if(head==NULL)
		return NULL;
	if(head->data==key)
		return head;
	else 
		return searchx(head->next,key);
}

bool checkallfurther(node * head,node* head1,node* temp,node* p)
{
	while(temp!=NULL)
	{
		if(temp->data!=p->data){
			return false;
			break;
		}

		temp=temp->next;
		p=p->next;

	}
	return true;
}


void insertion_circular(node *& head, node * head1)
{
	int data;

	node* temp=head1;

	while(temp!=NULL)
	{
		data=temp->data;

		node * p=searchx(head,data);
		if(p!=NULL)
		{
			if(checkallfurther(head,head1,temp,p))
			{
				
				return;				
			}
		}
		insertattail(head,data);
		temp=temp->next;
	}

}
void print_answer(node* h){

    map<int,int> m;
    while(h){
        if(m.count(h->data)){
            return;
        }
        else{
            cout<<h->data<<" ";
            m[h->data]=h->data;
        }
        h=h->next;
    }
}
int main()
{ 
	node * head1=NULL;
	node * head=NULL;
	insertlist(head1);
	print_answer(head1);
	return 0;
}
