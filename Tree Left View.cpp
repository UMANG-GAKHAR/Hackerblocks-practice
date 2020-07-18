// tree top view
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int d){
        data = d;
        left = right = NULL;
    }
};


node *insert(node *root , int d , queue<node*> &Q){
    node *new_node = NULL;
    if(d != -1)
        new_node = new node(d);
    if(root == NULL){
        root = new_node;
    }
    else if(Q.front()->left == NULL){
        Q.front()->left = new_node;
    }
    else if(Q.front()->right == NULL){
        Q.front()->right = new_node;
        Q.pop();
    }
    Q.push(new_node);
    return root;
}

void print(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
node *buildTree(){ 
  
   	queue<node*> q;
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    node* root = new node(d);
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        node *left, *right;
        left = right = NULL;
        cin>>d;
        if(d!=-1)
            left = new node(d);
        cin>>d;
        if(d!=-1)
            right = new node(d);
        tmp->left = left;
        tmp->right = right;
        if(left!=NULL)
            q.push(left);
        if(right!=NULL)
            q.push(right);
    }
    return root;
}


void left_view(node *root , int current_level = 0){
    static int max_reached_level = -1;
    if(root == NULL){
        return;
    }

    if(current_level > max_reached_level){
        max_reached_level = current_level;
        cout<<root->data<<" ";
    }
    left_view(root->left , current_level+1);
    left_view(root->right , current_level+1);
    return;
}

void BFS(node *root){
    if(root == NULL){
        return;
    }

    queue <node*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty()){
        node *front = Q.front();
        Q.pop();
        if(front == NULL){
            cout<<endl;
            if(!Q.empty()){
                Q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left){
                Q.push(front->left);
            }
            if(front->right){
                Q.push(front->right);
            }
        }
    }
}
int main(){
    node *root = buildTree();
    //BFS(root);
    left_view(root);
    return 0;
}
