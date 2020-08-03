#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define pii pair<long long,long long>
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define PI 3.14159265
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define INF 1000000009
#define mod 1000000007
char arr[300045];
ll bit[300045][30];
void update(ll id,ll v,ll n,ll val)
{
    while(id<=n)
    {
        bit[id][v]+=val;
        id += (id & -id);
    }
}
ll temp[30];
void query(ll id)
{
    while(id)
    {
        F(i,0,25)
        {
            temp[i] += bit[id][i];
        }
        id -= (id & -id);
    }
}
int main() 
{
    std::ios::sync_with_stdio(false);
    ll n,q;
    cin>>n>>q;
    F(i,1,n)
    {
        cin>>arr[i];
        update(i,arr[i]-'a',n,1);
    }
    /*F(i,1,n)
    {
        F(j,0,25)
        {
            cout<<bit[i][j]<<" ";
        }
        cout<<endl;
    }*/
    ll cnt[30];
    memset(cnt,0,sizeof(cnt));
    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll id;
            char c;
            cin>>id>>c;
            update(id,arr[id]-'a',n,-1);
            update(id,c-'a',n,1);
            arr[id] = c;
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            memset(temp,0,sizeof(temp));
            query(r);
            F(i,0,25)
            {
                cnt[i] = temp[i];
            }
            memset(temp,0,sizeof(temp));
            query(l-1);
            F(i,0,25)
            {
                cnt[i] -= temp[i];
            }
            ll len = r-l+1;
            ll c1=0,c2=0;
            F(i,0,25)
            {
                //cout<<cnt[i]<<" ";
                if(cnt[i]%2==0 && cnt[i]>0)
                    c1++;
                else if(cnt[i]%2==1 && cnt[i]>0)
                    c2++;
            }
            //cout<<endl;
            if(c2<=1)
                cout<<"yes";
            else
                cout<<"no";
            cout<<"\n";
        }
    }
    return 0;
}
