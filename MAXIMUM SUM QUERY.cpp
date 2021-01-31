#include<iostream>
#include<stdio.h>
#define INT_MIN -10000000000
#define nn 100100
#define mp make_pair
using namespace std;
long long int m[nn];
long long tree[4*nn],ltree[4*nn],rtree[4*nn],mtree[4*nn];
long long int max(long long int a,long long int b)
{
    return (a>b)?a:b;
}
void build(int node,int st,int en)
{
    if(st>en)
    {
        return;
    }
    if(st==en) //leaf node
    {
        tree[node]=m[st];    //total
        ltree[node]=m[st];  //left
        rtree[node]=m[st];  //right
        mtree[node]=m[st];  //middle...this is imp
        return;
    }
    int mid=(st+en)/2;
    build(2*node+1,st,mid);
    build(2*node +2,mid+1,en);
    //check for errors here
    tree[node]=tree[2*node+1]+tree[2*node+2];
    ltree[node]=max(ltree[2*node+1],max(tree[2*node+1],max(tree[2*node+1]+ltree[2*node+2],tree[node])));//this is 100% correct
    rtree[node]=max(rtree[2*node+2],max(tree[2*node+2],max(tree[2*node+2]+rtree[2*node+1],tree[node]))); //this is also correct
    //doubt in mtree...but acc to me its correct
    mtree[node]=max(mtree[2*node+1],max(mtree[2*node+2],max(tree[node],max(ltree[node],max(rtree[node],rtree[2*node+1]+ltree[2*node+2])))));
    //hopefully there is no error in this function
    return;
}
pair<pair<long long int,long long int>,pair<long long int,long long int> > query(int node,int st,int en,int l,int r) // returns maximum in all four trees
{
    if(st>en)
    {
        return make_pair(make_pair(INT_MIN,INT_MIN),make_pair(INT_MIN,INT_MIN));
    }
    if(st>r || en<l)  //out of range
    {
        return make_pair(make_pair(INT_MIN,INT_MIN),make_pair(INT_MIN,INT_MIN));
    }
    if(st>=l && en<=r)  //totally in range
    {
        return make_pair(make_pair(tree[node],ltree[node]),make_pair(rtree[node],mtree[node])); //returns the nodes as it is...obvio...
    }
    //partially in range
    int mid=(st+en)/2;
    pair<pair<long long int,long long int>,pair<long long int,long long int> >p1=query(2*node+1,st,mid,l,r);
    pair<pair<long long int,long long int>,pair<long long int,long long int> >p2=query(2*node+2,mid+1,en,l,r);

    long long int total=p1.first.first+p2.first.first;
    long long int left=max(p1.first.second,max(p1.first.first,max(p1.first.first+p2.first.second,total)));
    long long int right=max(p2.second.first,max(p2.first.first,max(p2.first.first+p1.second.first,total)));
    
    long long int middle=max(total,max(left,max(right,max(p1.second.second,max(p2.second.second,p1.second.first+p2.first.second)))));

    return make_pair(make_pair(total,left),make_pair(right,middle));

}
int main()
{
   
    int n,q,x,y;
    pair<pair<long long int,long long int>,pair<long long int,long long int> >tmp;
    cin>>n;
    for(int i=0;i<=4*n;i++)
    {
        tree[i]=INT_MIN;
        ltree[i]=INT_MIN;
        rtree[i]=INT_MIN;
        mtree[i]=INT_MIN;
    }
    long long int ans;
    ans=INT_MIN;
    for(long long int i=0;i<n;i++)
        cin>>m[i];
    build(0,0,n-1);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        tmp=query(0,0,n-1,x-1,y-1);
        ans=max(tmp.first.first,max(tmp.first.second,max(tmp.second.first,tmp.second.second)));
        cout<<ans<<endl;
    }
    return 0;
}
