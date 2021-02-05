#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 155000;
long long t[MAXN], f[MAXN];
int n;
int a[MAXN], w[MAXN];
 
void Add(int z, long long w)
{
	z += 1;
	for (; z < MAXN; z += z & (-z))
		t[z] = max(t[z], w);
}
 
long long GetMax(int z)
{
	long long res = 0;  z += 1;
	for (; z; z -= z & (-z))
		res = max(res, t[z]);
	return res;
}
 
long long Work()
{
	memset(t, 0, sizeof(t));
	memset(f, 0, sizeof(f));
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> a[i];
	memcpy(w, a, sizeof(a));
	sort(w, w + n);
	int m = unique(w, w + n) - w;
 
	for (int i = 0; i < n; i ++)
		a[i] = lower_bound(w, w + m, a[i]) - w;
 
	for (int i = 0; i < n; i ++)
		cin >> w[i];
	long long ans = 0;
	for (int i = 0; i < n; i ++)
	{
		f[i] = GetMax(a[i] - 1) + w[i];
		ans = max(ans, f[i]);
		Add(a[i], f[i]);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int tt = 0; tt < T; tt ++)
		cout << Work() << endl;
	return 0;
}
