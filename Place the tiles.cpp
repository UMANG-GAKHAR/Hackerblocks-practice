#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)
#define ll long long int
#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)

#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

int main()
{
   freopen("output.txt","w",stdout);
  ll t=1;
  while(t--){
    ll n;
    cin>>n;
    ll a=1;
    ll b=2;

    if(n==1)cout<<a<<endl;  // base case 1.
    else if(n==2)cout<<b<<endl; // base case 2.
    else{
      ll c;
      for(ll i=3;i<=n;i++){
        c=a+b;
        c%=mod;
        a=b;
        b=c;
      }
      cout<<c<<endl;
    }
  }
}
