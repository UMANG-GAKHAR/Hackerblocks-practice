#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
#define ff              first
#define ss              second
#define pb              push_back
#define mp              make_pair
#define pii             pair<lli,lli>
#define vi              vector<lli>
#define mii             map<lli,lli>
#define pqb             priority_queue<lli>
#define pqs             priority_queue<lli,vi,greater<lli> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            lli x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ONLINE_JUDGE
typedef tree<lli, null_type, less<lli>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void zanj0()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void out(vector < vector <lli> >& v) {
	for (lli i = 0; i < v.size(); i++) {
		for (lli j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void solve() {
	lli n, k;
	cin >> n >> k;
	vector < vector <lli> > v(n + 20, vector <lli>(n + 20));

	for (lli i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (lli j = 1; j <= n; j++) {
			v[i][j] = s[j - 1] == 'B' ? 0 : 1;
		}
	}
	//out(v);
	vector < vector <lli> > prefixTop(v.begin(), v.end());
	for (lli i = 1; i < v.size(); i++) {
		for (lli j = 0; j < v[i].size(); j++) {
			prefixTop[i][j] += prefixTop[i - 1][j];
		}
	}
	vector < vector <lli> > prefixLeft(v.begin(), v.end());
	for (lli i = 0; i < v.size(); i++) {
		for (lli j = 1; j < v[i].size(); j++) {
			prefixLeft[i][j] += prefixLeft[i][j - 1];
		}
	}
	//out(prefixTop);
	//out(prefixLeft);
	vector < vector <lli> > suffixBottom(v.begin(), v.end());
	vector < vector <lli> > suffixRight(v.begin(), v.end());
	for (lli i = v.size() - 2; i >= 0; i--) {
		for (lli j = 0; j < v[i].size(); j++) {
			suffixBottom[i][j] += suffixBottom[i + 1][j];
		}
	}
	for (lli i = v.size() - 1; i >= 0; i--) {
		for (lli j = v[i].size() - 2; j >= 0; j--) {
			suffixRight[i][j] += suffixRight[i][j + 1];
		}
	}
	//out(suffixBottom);
	//out(suffixRight);
	vector < vector <lli> > validCol(n + 20, vector <lli>(n + 20));
	vector < vector <lli> > validRow(n + 20, vector <lli>(n + 20));
	for (lli i = 1; i + k - 1 <= n; i++) {
		for (lli j = n;  j >= 0; j--) {
			lli oneAtTop = prefixTop[i - 1][j];
			lli oneAtBottom = suffixBottom[i + k][j];
			lli total = n;

			validCol[i][j] = ((oneAtBottom + oneAtTop + k) == total) + validCol[i][j + 1];
		}
	}
	//cout << "Okay!"  << endl;
	//out(validCol);
	for (lli i = v.size() - 2; i >= 0; i--) {
		for (lli j = 1; j + k - 1 <= n; j++) {

			lli oneAtLeft = prefixLeft[i][j - 1];
			lli oneAtRight = suffixRight[i][j + k];
			//cout << i << " " << j << " " << oneAtLeft << " " << oneAtRight << " " << k << endl;
			validRow[i][j] = ((oneAtRight + oneAtLeft + k) == n) + validRow[i + 1][j];
		}
	}

	//out(validRow);
	lli ret = 0;
	lli x = -1, y = -1;
	for (lli i = 1; i + k - 1 <= n; i++) {
		for (lli j = 1 ; j + k - 1 <= n; j++) {
			lli temp = validCol[i][j] - validCol[i][j + k];
			lli rows = validRow[i][j] - validRow[i + k][j];
			//cout << i << " " << j << " " << temp << " " << rows << endl;
			lli z = temp + rows;
			if (z > ret) {
				ret = z;
				x = i;
				y = j;
			}
		}
	}
	for (lli i = 1; i <= n; i++) {
		lli temp = 0;
		for (lli j = 1; j <= n; j++) {
			if (i >= x && i <= x + k - 1 && j >= y && j <= y + k - 1) continue;
			temp += v[i][j];
		}
		ret += temp == n;
	}
	cout << ret << endl;
}
int main()
{
	zanj0();
	solve();
	return 0;
}
