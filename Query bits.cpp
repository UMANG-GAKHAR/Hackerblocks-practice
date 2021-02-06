#include <bits/stdc++.h>
#define nn 200100
#define ll long long int
#define inf 1000000000000000000ll
#define logn 20
#define mod 1000000007ll
using namespace std;
ll pow(ll a,ll p,ll m=mod)
{ll res=1;while(p>0){if(p&1)res=(res*a)%m;a=(a*a)%m;p>>=1;}
return res;}
ll t[nn<<2],lz[nn<<2];
void lazy_up(int node,int st,int en)
{
    if(lz[node]!=-1)
    {
        t[node]=(pow(2,en-st+1,mod)-1)*lz[node];
        if(st!=en)
        {
            lz[node*2+1]=lz[node];
            lz[node*2+2]=lz[node];
        }
        lz[node]=-1;
    }
}
void update(int node,int st,int en,int l,int r,int x)
{
    lazy_up(node,st,en); //updating pending lazy updates.
    if(st>r || en<l)
        return;
    if(st>=l && en<=r)
    {
        t[node]=(pow(2,en-st+1,mod)-1)*x;
        if(st!=en)
        {
            lz[node*2+1]=x;
            lz[node*2+2]=x;
        }
        return;
    }
    int mid=st+en>>1;
    update(node*2+1,st,mid,l,r,x);
    update(node*2+2,mid+1,en,l,r,x);
    t[node]=(t[node*2+1]*pow(2,en-mid,mod)%mod+t[node*2+2])%mod; //merging children to form parent
}

ll query(int node,int st,int en,int l,int r)
{
    lazy_up(node,st,en); //updating pending lazy updates.
    if(st>r || en<l)
        return 0;
    if(st>=l && en<=r)
    {
        return t[node];
    }
    int mid=st+en>>1;
    int p1=query(node*2+1,st,mid,l,r);
    int p2=query(node*2+2,mid+1,en,l,r);
    if(r<=mid)
        return p1;
    return (p1*pow(2,min(en,r)-mid,mod)%mod+p2)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        int x,l,r;
        cin>>x>>l>>r;
        assert(x>=0 && x<=2 && l<=r && l<n);
        if(x<2)
            update(0,0,n-1,l,r,x);
        else
        {
            ll ans=query(0,0,n-1,l,r);
        //    assert(ans>=0 && ans<mod);
            cout<<ans<<endl;
        }
    }
    return 0;
}
