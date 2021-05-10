#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define ll long long
void buildTree(ll *a,ll s,ll e,ll *tree,ll index)
{
    //base case
    if(s==e)
    {
        tree[index]=a[s];
        return;
    }
    //recursive case
    ll mid=(s+e)/2;
    buildTree(a,s,mid,tree,2*index);
    buildTree(a,mid+1,e,tree,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;   
}
ll Query(ll *tree,ll ss,ll se,ll qs,ll qe,ll index)
{
    //check for compplete overlap
    if(ss>=qs && se<=qe)
    {
        return tree[index];
    }
    //check for no overlap
    if(qe<ss || qs>se)
    {
        return INT_MAX;
    }
    //taking care of partial overlap
    ll mid=(ss+se)/2;
    ll left=Query(tree,ss,mid,qs,qe,2*index);
    ll right=Query(tree,mid+1,se,qs,qe,2*index+1);
    return min(left,right);
}
void updateNode(ll *tree,ll ss,ll se,ll i,ll increment,ll index)
{
    //cout<<"update is happening"<<endl;
    //check range
    if(i<ss || i>se )
    {
        return;
    }
    //base case
    if(ss==se)
    {
        tree[index]=increment;
        return;
    }
    ll mid=(ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    tree[index]=min(tree[2*index],tree[2*index+1]);
}

int main()
{
   
   ll n,q;
   cin>>n>>q;
   ll a[n];
   ll tree[4*n+1];
   
   for(ll i=0;i<n;i++)
   {
       cin>>a[i];
   }
   buildTree(a,0,n-1,tree,1);
   
   while(q--)
   {
       ll type,l,r;
       cin>>type>>l>>r;
       if(type==1)
       {
           //do this
         cout<<Query(tree,0,n-1,l-1,r-1,1)<<endl; //indices are 1-based in question, but 0-based for us, so we actuallu need l-1, r-1
           
           
       }
       else
       {
           //do that
           updateNode(tree,0,n-1,l-1,r,1); //again make the index 0-based (y is the value so dont change that, just change the index)
           
       }
   }
   
   return 0;
}
