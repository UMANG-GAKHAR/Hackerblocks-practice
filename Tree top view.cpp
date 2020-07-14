#include <iostream>
#include <queue>
#include <climits>
#include <map>
using namespace std;
class node{
    public:
        int data;
        int hd;
        node*left;
        node*right;

        node(int d){
            data=d;
            left=NULL;
            right=NULL;
            hd=INT_MAX;
        }
};
node *buildTree(){
    int d;
    cin>>d;
    node* root = NULL;
    if(d != -1){
        root = new node(d);
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            node *f = q.front();
            q.pop();
            int d1, d2;
            cin>>d1>>d2;
            if(d1 != -1){
                f->left = new node(d1);
                f->left->hd = f->hd - 1;
                q.push(f->left);
            }
            if(d2 != -1){
                f->right = new node(d2);
                f->right->hd = f->hd + 1;
                q.push(f->right);
            }
        }
    }
    return root;
}
void bfs2(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*front=q.front();
        
        if(front==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<front->data<<" ";
            q.pop();
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}
void treeTopView(node*root){
    queue<node*>q;
    map<int,int>m;
    int hd=0;
    root->hd=hd;
    q.push(root);
    while(!q.empty()){
        node*front=q.front();
        q.pop();
        if(m.find(front->hd)==m.end()){
            m[front->hd]=front->data;
        }
        if(front->left){
            front->left->hd=front->hd-1;
            q.push(front->left);
        }
        if(front->right){
            front->right->hd=front->hd+1;
            q.push(front->right);
        }
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
}
int main() {
    node*root=buildTree();
    treeTopView(root);
    cout<<endl;
}
