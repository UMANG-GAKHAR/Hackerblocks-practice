#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node(int d){
		data=d;
		next=NULL;
	}
};
void insert_at_tail(node *&head,int x){
	node *n=new node(x);
	if(head==NULL){
		head=n;
		n->next=NULL;
	}
	else{
		node *temp=head;
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next=n;
		n->next=NULL;
	}
}
void create_list(node *&head){
	int size;
	cin>>size;
	while(size>0){
		int data;
        cin>>data;
		insert_at_tail(head,data);
		size--;
	}
}
void reverse(node*&head){
    node*next;
    node*curr=head;
    node*prev=NULL;
    while(curr != NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
	head=prev;
}
bool compare(node*a,node*b){
    node*temp1=a;
    node*temp2=b;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data == temp2->data){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            return 0;
        }
    }
   
    return 1;
}
bool palindrome_check(node *&head){
	node *slow=head;
	node *fast=head;
	node *second=NULL;
	bool result=true;
	if(head!=NULL && head->next!= NULL){
		while(fast!=NULL && fast->next!=NULL ){
			fast=fast->next->next;
			if(fast==NULL){
				slow=slow->next;
				break;
			}
			if(fast->next==NULL){
				slow=slow->next->next;
				break;
			}
			slow=slow->next;
		}
		second=slow->next;
		slow->next=NULL;
		reverse(second);
		result=compare(head,second);
	}
	return result;
}
int main() {
	node* head=NULL;
	create_list(head);
	if(palindrome_check(head)){
		cout<<"true"<<endl;
	}
	else{
	  cout<<"false";
	}
	return 0;
}
