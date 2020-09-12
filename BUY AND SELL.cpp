#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(int i = a; i <= b; i++)
#define RF(i,a,b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define PI 3.14159265358979323846264338327950288
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define MX 200005
ll BIT[MX+5];
map <string,ll> mymap,mp;
void update(ll id,ll val)
{
    while(id < MX)
    {
        BIT[id] += val;
        id = id + (id & -id);
    }
}
ll query(ll id)
{
    ll sum = 0;
    while(id > 0)
    {
        sum += BIT[id];
        id = id - (id & -id);
    }
    return sum;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    F(i,1,n)
    {
        string s;
        cin>>s;
        ll cost;
        cin>>cost;
        mymap[s] = cost;
    }
    ll q;
    cin>>q;
    while(q--)
    {
        char ch;
        cin>>ch;
        if(ch == '+')
        {
            string s;
            cin>>s;
            mp[s]++;
            update(mymap[s],1);
        }
        else if(ch == '-')
        {
            string s;
            cin>>s;
            if(mp[s])
            {
                mp[s]--;
                update(mymap[s],-1);
            }
        }
        else
        {
            ll y;
            cin>>y;
            ll ans = query(MX) - query(y);
            cout<<ans<<endl;
        }
    }   
    return 0;
}
