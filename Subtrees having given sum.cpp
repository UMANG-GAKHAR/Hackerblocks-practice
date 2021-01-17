#include <iostream>
#include<queue>
using namespace std;
class Node{
  public:
     int val;
     Node* left;
     Node* right;
     Node(int val){
         this->val = val;
         left = NULL;
         right = NULL;
     }
};
Node* levelOrderInput(){
    int root_val; cin>>root_val;
    Node* root = new Node(root_val);
    queue<Node*> qu;    qu.push(root);
    while(!qu.empty()){
        Node* child = qu.front();
        qu.pop();
        int a,b; cin>>a>>b;
        if(a != -1){
           Node* n = new Node(a);
           qu.push(n);
           child->left = n;
        }
        if(b != -1){
            Node* n = new Node(b);
            qu.push(n);
            child->right = n;
        }
    }
    return root;
}
void levelOrder_print(Node* root){
    queue<Node*> qu;
    qu.push(root); qu.push(NULL);
    while(!qu.empty()){
        Node* n = qu.front();
        qu.pop();
        if(n != NULL){
            cout<<n->val<<" ";
            if(n->left) qu.push(n->left);
            if(n->right) qu.push(n->right);
        }
        else {
            cout<<endl;
            if(!qu.empty()) qu.push(NULL);
        }
    }
    return ;
}






// Definition of a Node of Binary Tree
// class Node{
//   public:
//      int val;
//      Node* left;
//      Node* right;
//      Node(int val){
//          this->val = val;
//          left = NULL;
//          right = NULL;
//      }
// };


pair<int,int> count(Node* root,int req_sum){
    if( root == NULL) return make_pair(0,0);

    pair<int,int> p1 = count(root->left,req_sum);
    pair<int,int> p2 = count(root->right,req_sum);

    int total_sum  = p1.second + p2.second + root->val;
    int counter = p1.first + p2.first;
    if(total_sum == req_sum) counter++;

   return make_pair(counter,total_sum);
}

int countSubtreesWithGivenSum(Node* root, int x){
    return count(root,x).first;
}

int main() {
     Node* root = levelOrderInput();
     int x; cin>>x;
     cout<<countSubtreesWithGivenSum(root,x);
     return 0;
}
