#include <iostream>
#include<algorithm>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* createTree(int inOrder[],int preOrder[],int s,int e){
    static int i=0;
    if(s>e){
        return NULL;
    }
    int element=preOrder[i];
    node* root=new node(element);
    int index=find(inOrder+s,inOrder+e+1,element)-inOrder;
    i++;
    root->left=createTree(inOrder,preOrder,s,index-1);
    root->right=createTree(inOrder,preOrder,index+1,e);
    return root;
}


class Pair{
public:
    int count;
    int small;
    int big;
};


Pair largestBST(node* root,int& ans){
    Pair p;
    if(root==NULL){
        p.small=0;
        p.big=0;
        p.count=0;
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        p.small=p.big=root->data;
        p.count=1;
        ans=max(ans,p.count);
        return p;
    }
    Pair lst=largestBST(root->left,ans);
    Pair rst=largestBST(root->right,ans);
    if(root->left!=NULL && root->right!=NULL){
        if(root->data>=lst.big && root->data < rst.small){
            p.count=lst.count+rst.count+1;
            p.small=lst.small;
            p.big=rst.big;
        }
        else{
            p.count=0;
            p.small=p.big=0;
        }
    }
    else if(root->left!=NULL && root->right==NULL){
        if(root->data >= lst.big){
            p.count=lst.count+1;
            p.small=lst.small;
            p.big=root->data;
        }
		else{
			p.count=0;
            p.small=p.big=0;
		}
    }
    else{
        if(root->data < rst.small){
            p.count=rst.count+1; 
            p.small=root->data;       
            p.big=rst.big;
        }
		else{
			p.count=0;
            p.small=p.big=0;
		}
    }
    ans=max(ans,p.count);
    return p;
}


int main() {
    int n;
    cin>>n;
    int preOrder[n];
    for(int i=0;i<n;i++){
        cin>>preOrder[i];
    }
    int inOrder[n];
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
    }
    node* root=createTree(inOrder,preOrder,0,n-1);
    int ans=0;
    largestBST(root,ans);
    cout<<ans<<endl;
    return 0;
}
