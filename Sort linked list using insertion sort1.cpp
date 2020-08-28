#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
	int data;
	node* next;

	node(int d)
	{
		data=d;
		next=NULL;
	}
};
/*
void insert_at_tail(node*& head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new node(data);
	return;
}

void buildlist(node* &head,int x)
{
	while(x>0)
	{
		int data;
		cin>>data;
		insert_at_tail(head,data);
		x--;
	}
	return;
}
*/
void insertion_sort(node* &head,int n)
{
	int data;
	cin>>data;
	head=new node(data);
	while(n>1)
	{
		cin>>data;
		if(head->data>=data)
		{
			node* ptr1=new node(data);
			ptr1->next=head;
			head=ptr1;
		}
		else
		{
			node* ptr2;
			node* temp=head->next;
            while(temp!=NULL && temp->data<data)
			{
				ptr2=temp;
				temp=temp->next;
			}
			ptr2->next=new node(data);
			ptr2->next->next=temp;
		}
		n--;
	}
}

void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main()
{
	node* head=NULL;
	int n;
	cin>>n;
	insertion_sort(head,n);
	print(head);
	return 0;
}
