#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int  power(ll int ans, ll int i, ll int p)
{
	if (i == 0)
	{
		return 1;
	}
	else
	{
		if (i & 1)
		{
			// ans
			return ((ans * power(ans, i - 1, p)) % p * ans) % p;
		}
		else
		{
			ll subp = power(ans, i / 2, p);
			subp = (subp * subp) % p;
			return (ans * subp) % p;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ll int a, n, p;
		cin >> a >> n >> p;
		ll int ans = a % p;
		for (int i = 2; i <= n; i++)
		{
			ans *= power(ans, i, p);
			ans %= p;
		}
		cout << ans % p << endl;

	}
	return 0;
}
