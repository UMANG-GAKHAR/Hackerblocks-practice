#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(ll i = a; i <= b; i++)
#define RF(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair<ll,ll>
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
ll n,arr[30],mincutdp[1005];
string s;
bool isvalid(ll st,ll en)
{
    F(i,st,en)
    {
        if(arr[s[i]-'a'] < (en-st+1))
            return 0;
    }
    return 1;
}
ll mincut(ll cur) 
{
    if(mincutdp[cur]!=-1)
        return mincutdp[cur];
    if(cur == 0)
        return mincutdp[cur] = 0;
    ll ans = INF;
    RF(i,cur,1)
    {
        if(!isvalid(i,cur)) 
        {
            ans = min(ans,1 + mincut(i));
            break;
        }
    }
    if(ans == INF)
        return mincutdp[cur] = 1;
    return mincutdp[cur] = ans;
}
ll dp2[1005];
int main() 
{
    std::ios::sync_with_stdio(false);
    //memset(mincutdp,-1,sizeof(mincutdp));
    cin>>n>>s;
    s = "*" + s;
    F(i,0,25)
        cin>>arr[i];
    //cout<<mincut(n)<<endl;
    dp2[0] = 0; // bottom up dp
    F(i,1,n)
    {
        dp2[i] = 1;
        RF(j,i,1)
        {
            if(!isvalid(j,i))
            {
                dp2[i] = 1 + dp2[j]; 
                break;
            }
        }
    }
    cout<<dp2[n]<<endl;
    return 0;
}
