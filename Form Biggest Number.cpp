#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define w(x) int x; cin>>x; while(x--)
void sm()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
bool cmpr(string a, string b) {
   return a+b > b+a;
}

int32_t main()
{
	sm();
	w(t) {
		int n;
		cin >> n;
		string a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n,cmpr);
		for (int i = 0; i < n; i++) {
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}
