#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void print(node* root) {
     if (!root) {
         return;
     }
     cout << root->data << " ";
     print(root->left);
     print(root->right);
 }
node* makeTree() {
    int rootVal, children;
    cin >> rootVal;
    node* root = new node(rootVal);
    cin >> children;
    if (children == 0) {
        return root;
    }
    root->left = makeTree();
    if (children == 2) {
        root->right = makeTree();
    }
    return root;
}
void calcSum(node* root, int k, int &sum) {
    if (!root) {
        return;
    }
    if (k == 0) {
        sum += root->data;
        return;
    }
    calcSum(root->left, k - 1, sum);
    calcSum(root->right, k - 1, sum);
}
int main() {
    node* root = makeTree();
    int k;
    cin >> k;
    int sum = 0;
    calcSum(root, k, sum);
    cout << sum;
}
