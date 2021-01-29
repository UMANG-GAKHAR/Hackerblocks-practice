#include<bits/stdc++.h> 
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* insertInBST(node *root,int data){
    
    if(root==NULL){
        return new node(data);
    }
    
    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }
    return root;
}

node* buildBalancedBst(int l,int r,int arr[]){

    if(l>r){
        return NULL;
    }
   // cout<<"Building Root\n";
    int mid=(l+r)/2;
    node *root = new node(arr[mid]);
    root->left=buildBalancedBst(l,mid-1,arr);
    root->right=buildBalancedBst(mid+1,r,arr);
    return root;
}
void printBST(node *root){
    if(root==NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout<<root->data<<" ";
    printBST(root->left);
    printBST(root->right);
}
int main() {
   int t;
   cin>>t;
   node *root=NULL;
   while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    root=buildBalancedBst(0,n-1,arr);
    printBST(root);
    cout<<endl;
   }
}
