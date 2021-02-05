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
string s;
ll final_mask , n , m , dp[(1<<18)+10][105];
ll f(ll mask , ll rem)
{
    if(mask == final_mask) // if all indices of string have been used
    {
        if(rem) // if rem is not 0
            return 0;
        return 1; // if rem is 0
    }
    if(dp[mask][rem] != -1) // if already calculated
        return dp[mask][rem];
    //debug(mask);
    ll ret = 0;
    F(i,0,9) //try putting all possible digits at first empty valid posittion in mask one by one
    {
        if(mask == 0 && i == 0)
            continue;
        F(j,0,n-1)
        {
            if( (s[j] != i+'0') || (mask & (1<<j) ) ) // if i is not present in n or s already added in mask
                continue;
            ret += f(mask | (1<<j) , (rem*10 + i)%m); // add digit i and set j true in mask
            break;
        }
    }
    return dp[mask][rem] = ret;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    //freopen("i5.txt","r",stdin);
    //freopen("o5.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>s>>m;
        n = s.length();
        final_mask = (1ll<<n) - 1ll;
        cout<<f(0,0)<<endl;
    }
    return 0;
}
