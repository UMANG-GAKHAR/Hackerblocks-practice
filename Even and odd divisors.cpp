#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vll vector<ll>
vll primes;
vll seive;
vll divisors;
void Seive(ll n) {
	seive.resize(n + 5, 1);
	seive[1] = 0, seive[0] = 0;
	divisors.resize(n + 5);
	divisors[1] = -1;
	divisors[2] = 1;
	for ( int i = 1; i  <= n ; i++) {
		for ( int j = i; j <= n; j += i) {
			if ( i & 1)
				divisors[j] -= i;
			else
				divisors[j] += i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, t, a, b, c, d;
	t = 1;
	cin >> t;
	Seive(100001);
	while (t--) {
        
		cin >> n;
		cout << divisors[n] << endl;
	}

}
