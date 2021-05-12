#include<iostream>
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
node* buildTree(int* preorder,int* inorder,int s,int e)
{
	if(s>e)
		return NULL;
    static int idx=0;
	node* root=new node(preorder[idx]);
	int index=-1;
	for(int j=s;j<=e;j++)
	{
		if(inorder[j]==preorder[idx])
		{
			index=j;
			break;
		}
	}
	idx+=1;
	root->left=buildTree(preorder,inorder,s,index-1);
	root->right=buildTree(preorder,inorder,index+1,e);
	return root;
}
//thoda update
void printStyle(node *root)
{
    if(root==NULL)
        return ;
    if(root->left==NULL)
        cout<<"END => ";
    else
        cout<<root->left->data<<" => ";
    cout<<root->data;    
    if(root->right==NULL)
        cout<<" <= END"<<endl;
    else
        cout<<" <= "<<root->right->data<<endl;
    printStyle(root->left);
    printStyle(root->right);

}
int main() {
	int n,m;
	cin>>n;
	int preorder[n];
	for(int i=0;i<n;i++)
		cin>>preorder[i];
	cin>>m;
	int inorder[m];
	for(int i=0;i<m;i++)
		cin>>inorder[i];
	node* root=buildTree(preorder,inorder,0,n-1);
	printStyle(root);
	return 0;
}
