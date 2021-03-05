#include <bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007
#define ll  long long int
#define vi  vector<ll>

ll x,y;
ll gcd(ll a,ll b){ if(a==0) {x=0,y=1; return b;}ll gc=gcd(b%a,a);ll temp;temp=x;x=y-(b/a)*temp;y=temp;return gc;}

//(a^x)%m
ll fastPow(ll a, ll x,ll m=MOD){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; } 
int main() {
    sync;

    int n;
    cin>>n;

    vi v(n);
    cin >> v[0];
    ll g = v[0];
    ll f = v[0];

    for (int i = 1; i < n; ++i) {
        cin>>v[i];
        g = gcd(g, v[i]);
        f = (f*v[i])%MOD;
    }

    cout << fastPow(f,g) << "\n";


    return 0;
}
