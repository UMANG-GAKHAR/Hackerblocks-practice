#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;
struct node{
    int data;
    node *next;
    node (){
        next=NULL;
    }
};
node *first=NULL,*second=NULL,*third=NULL;
void create(int *a,int n){
    if(n==0)
      return;
    int i;
    node*temp,*last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;

    }
}
void create2(int *a,int n){
    int i;
    if(n==0)
    return;
    node*temp,*last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=temp;

    }
}
void display(struct node *p)
{
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

}

void merge(struct node *p,struct node *q){
    struct node *last;
    if(p==NULL){
        third=q;
        return;
    }
    if(q==NULL){
        third=p;
        return;
    }
    if(p->data<q->data){
        third=p;
        p=p->next;
        third->next=NULL;
        last=third;
    }
    else{
        third=q;
        q=q->next;
        third->next=NULL;
        last=third;
    }
    while(p&&q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
           last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

        if(p)
        last->next=p;
        if(q)
        last->next=q;
    
}
int main(){
	int t;
	cin>>t;
	while(t--){
        first=NULL;
        second=NULL;
        third=NULL;
    int n;
    cin>>n;
	if(n!=0){
    int arr[n];
    for (int i = 0; i < n; i++)
    {
    cin>>arr[i];
    }
	create(arr,n);
	}
    
    int n2;
    cin>>n2;
	if(n2!=0){
    int arr2[n2];
    for(int i=0;i<n2;i++)
    cin>>arr2[i];
    create2(arr2,n2);
	}
    
   merge(first,second);
   display(third);
   cout<<"\n";
	}
    return 0;

}
