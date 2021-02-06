#include "bits/stdc++.h"
using namespace std;
#define F(i,a,b) for(ll i = a; i <= b; i++)
#define RF(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair
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

bool primes[1000006];
void sieve()
{
    for(ll i=3;i*i<=100000;i++)
    {
        if(primes[i] == 0)
        {
            for(ll j = 1LL*i*i; j <= 100000;j += 1LL*2*i)
                primes[j] = 1;
        }
    }
}
vector<int>  divisors[1000006];
void find_div()
{
    F(i,1,100000)
    {
        for(ll j = i; j <= 100000; j += i)
            divisors[j].pb(i);
    }
}

ll grundy[1000006];

ll find_mex(set<int>  s)
{
    ll m = 0;
    while(1)
    {
        if(s.find(m) == s.end())
            return m;
        m++;
    }
}

ll calculate_grundy(ll n)
{
    // grundy for prime numbers and 1 will be 0 according to problem
    if(n == 1)
        return 0;
    if(n==2 || (n%2 != 0 && primes[n]==0))
        return 1;
    if(grundy[n] != -1)
        return grundy[n];
    // we can break n into any of its divisors not equal to n
    ll sz = divisors[n].size();

    set<int>  possible_states;

    possible_states.clear();

    F(i,0,sz-1)
    {
        if(divisors[n][i] != n)
        {
            ll d = divisors[n][i];
            ll numofpiles = n/d;
            ll g = calculate_grundy(divisors[n][i]);
            if((numofpiles&1) == 0 ) // if piles are odd grundy will be g else 0
            {
                g = 0;
            }
            possible_states.insert(g);
        }
    }
    return (grundy[n] = find_mex(possible_states));
}

int main() 
{	
	    
    std::ios::sync_with_stdio(false);

    memset(grundy,-1,sizeof(grundy));

    sieve();
    find_div();
    
    ll t; 
    cin>>t;

    while(t--)
    {
        ll n,m;
        cin>>n;
        ll xorr = 0ll;
        F(i,1,n)
        {
            cin>>m;
            ll g = calculate_grundy(m);
            xorr ^= g;
        }
        if(xorr) 
            cout<< 1 <<endl;
        else cout << 2<< endl;
  }
}
