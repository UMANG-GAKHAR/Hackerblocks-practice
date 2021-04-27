#include<bits/stdc++.h>
#define M1 1000000007
#define M2 998244353
#define ll long long int
#define N (int)1e5+3
#define test(t) while(t--)
#define PI acos(-1.0)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mii map<int,int>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repp(i,b,a) for(ll i=b-1;i>=a;i--)
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define F first
#define S second
#define PB push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define V(a) vector<a>
#define M(a,b) map<a,b>
#define endl '\n'
#define all(x) begin(x),end(x)
#define allr(x) rbegin(x),rend(x)
#define pr(a) cout<<a<<endl;
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
using namespace std;
ll CalculateMex(set<ll> Set){
    ll Mex = 0;
    while(Set.find(Mex)!=Set.end()){
        Mex++;
    }
    return Mex;
}
inline void INP()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);   
	    freopen("output.txt","w",stdout);
	#endif 
}
ll m,n,s;
pll v[102];
ll dp[102][10002][102];
ll ansit(ll i,ll siz,ll color){
    while(v[i].F != color && i<n) i++;

    if (i == n){
        if(siz <= s && color == m+1){
            return siz;
        }
        else return 0;
    }
    if (siz>=s || color>m) return 0;

    if (dp[i][siz][color] != -1) return dp[i][siz][color];

    ll myans = 0;
    
    rep(j,i,n){
        if (v[j].F != color) break;
        // If I choose to pick it up
        myans = max(myans,ansit(j+1,siz+v[j].S,color+1));
    }
    return dp[i][siz][color] = myans;
}
void solve()
{
    cin>>n>>m>>s;
    ll w[n],c[n];
    rep(i,0,n) cin >> w[i];
    rep(i,0,n) cin >> c[i];
    rep(i,0,n) v[i] = {c[i],w[i]};
    sort(v,v+n);
    clr(dp,-1);
    ll ans = ansit(0,0,1);
    cout << (ans>0?s-ans:-1)  << endl;

}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    test(t){
        solve();
    }
    return 0;
}
