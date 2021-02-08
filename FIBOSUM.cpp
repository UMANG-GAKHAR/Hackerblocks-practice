#include <bits/stdc++.h>
using namespace std;
#define boost  ios_base::sync_with_stdio(false);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define f(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define rf(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define ms(a,b) memset((a),(b),sizeof(a))
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

#define abs(x) ((x<0)?(-(x)):(x))
#define MAX 100005
#define inf LLONG_MAX
#define MIN INT_MIN
//typedef
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}

void multiply(ll F[2][2], ll M[2][2]);
void power(ll F[2][2], ll n);

/* function that returns nth Fibonacci number */
int fib(ll n)
{
  ll F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
void power(ll F[2][2], ll n)
{
  if( n == 0 || n == 1)
      return;
  ll M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}
void multiply(ll F[2][2], ll M[2][2])
{
  int x =  (F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod;
  int y =  (F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod;
  int z =  (F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod;
  int w =  (F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod;

  F[0][0] = x%mod;
  F[0][1] = y%mod;
  F[1][0] = z%mod;
  F[1][1] = w%mod;
}
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;cin>>t;int n,m;
    while(t--)
    {
      cin>>n>>m;
      cout<<((fib(m+2)%mod-fib(n+2-1)%mod)+mod)%mod<<endl;
    }
    return 0;
}
