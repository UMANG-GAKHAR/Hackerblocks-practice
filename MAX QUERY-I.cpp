#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll query(vector<vector<ll>> &tree,int ss,int se,int qs,int qe,int index,ll k)
{
    if(qe<ss || qs>se)
    {
        return 0;
    }

    else if(ss>=qs && se<=qe)
    {

        return tree[index].end()-lower_bound(tree[index].begin(),tree[index].end(),k);  
    }


    int mid = (ss+se)/2;
    ll leftAns = query(tree,ss,mid,qs,qe,2*index,k);
    ll rightAns  = query(tree,mid+1,se,qs,qe,2*index+1,k);
    return  (leftAns + rightAns);
}


void BuildTree(vector<vector<ll>> &tree,vector<ll> &arr,int s,int e,int index)
{
    if(s==e)
    {
        tree[index].push_back(arr[s]);
        return;
    }


    int mid=(s+e)/2;
    BuildTree(tree,arr,s,mid,index*2);
    BuildTree(tree,arr,mid+1,e,index*2+1);
    merge(tree[2*index].begin(),tree[2*index].end(),tree[2*index+1].begin(),tree[2*index+1].end(),back_inserter(tree[index]));
    return;

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n;

    vector<ll> arr(n);

    vector<vector<ll>> tree(4*n+1); 


    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    BuildTree(tree,arr,0,n-1,1);

    cin>>q;

    while(q--) 
    {
        int l,r;
        ll k;
        cin>>l>>r>>k;
        l--;
        r--;

        cout<<query(tree,0,n-1,l,r,1,k)<<endl;

    }
    return 0;
}
