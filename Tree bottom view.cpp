#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;

	node(int d)
	{
		data=d;
		left=right=NULL;
	}

};
node *createlevelorder()
{
    int d;
    cin>>d;
    node *root=new node(d);
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node *f=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            f->left=new node(c1);
            q.push(f->left);
        }
        if(c2!=-1)
        {
            f->right=new node(c2);
            q.push(f->right);
        }
    }
    return root;
}
void vop(node *root,int level,int d,map<int,pair<int,int> >&m)
{
    if(root==NULL)
    {
        return;
    }
    if(m.find(d)==m.end() or level>=m[d].second)
        m[d] = {root->data,level};

    vop(root->left,level+1,d-1,m);
    vop(root->right,level+1,d+1,m);
}


int main()
{
    node *root=createlevelorder();
	
    map<int,pair<int,int> >m;
    vop(root,0,0,m);

    for(auto it:m)
    {
        cout<<it.second.first<<" ";
    }
	return 0;
}
