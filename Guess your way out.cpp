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
ll BIT[200005];
void update(ll id,ll val) {
    for(ll i=id;i<=200000;i+=i&-i) BIT[i]+=val;
}
ll query(ll id) {
    ll sum=0;
    for(ll i=id;i>0;i-=i&-i) sum+=BIT[i];
    return sum;
}
ll ans = 0;
void f(ll h,ll n,bool dir)
{
    if(h == 0)
        return;
    ll lim = ceil(pow(2ll,h-1));
    if(n <= lim) 
    {
        if(dir == 0)
        {
            ans++;
            f(h-1,n,!dir);
            return;
        }
        else // going right
        {
            ans += ceil(pow(2ll,h));
            f(h-1,n,dir);
            return;
        }
    }
    else // right child
    {
        if(dir == 0) // going left
        {
            ans += ceil(pow(2ll,h));
            f(h-1,n-ceil(pow(2ll,h-1)),dir);
            return;
        }
        else // going right
        {
            ans++;
            f(h-1,n-ceil(pow(2ll,h-1)),!dir);
            return;
        }
    }
}
int main() 
{
    std::ios::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ans = 0;
        ll h,n;
        cin>>h>>n;
        f(h,n,0);
        cout<<ans<<endl;
    }
    return 0;
}
