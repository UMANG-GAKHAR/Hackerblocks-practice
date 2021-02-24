#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define fo(i,n) for(i=0;i<n;i++)
#define set(a) memset(a,0,sizeof(a))
#define MOD 1000000007
#define test(t) ll t; cin>>t; while(t--)
class node
{
public:
    int data;
    node*left;
    node*right;

    node(int d)
    {
        data =d;
        left=NULL;
        right=NULL;
    }
};
node*binary_tree(string s)
{
	node*root1;
	if(s=="true")
	{
		int d;
		cin>>d;
		root1=new node(d);
		string l;
		cin>>l;
		if(l=="true")
		root1->left=binary_tree("true");

		string r;
		cin>>r;
		if(r=="true")
		root1->right=binary_tree("true");
	}

	if(s=="false")
	return NULL;

	return root1;
}
void print_pre_order(node*root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    print_pre_order(root->left);
    print_pre_order(root->right);   
}

bool compare(node*root1,node*root2)
{
	if(root1==NULL&&root2==NULL)//changed 
	return true;

	else if(root1==NULL and root2!=NULL)
	return false;

	else if(root2==NULL and root1!=NULL)
	return false;

	return (compare(root1->left,root2->left)&&compare(root1->right,root2->right));
	//compare(root1->right,root2->right);

	//return true;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	node*root1,*root2;

	root1=binary_tree("true");
	root2=binary_tree("true");

	if(compare(root1,root2)==1)
	cout<<"true"<<endl;

	else 
	cout<<"false"<<endl;
	return 0;
}
