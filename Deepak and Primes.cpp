#include<bits/stdc++.h>
using namespace std;

#define 	ff              	first
#define 	ss              	second
#define 	int             	long long int
#define 	pb              	push_back
#define 	pii             	pair<int,int>
#define 	vi              	vector<int>
#define 	maxpq 	            priority_queue<int>
#define 	minpq   	        priority_queue<int,vi,greater<int> >
#define 	um   	        	unordered_map
#define 	setbits(no)     	__builtin_popcountll(no)
#define 	mod             	1000000007
#define 	w(t)            	int t; cin>>t; while(t--)

// // typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void h_g()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	// h_g();

	int maxx = 7400000;
	bool prime[maxx+2] = {0};
	prime[2] = 1;
	vi v;
    v.push_back(2);
	for (int i = 3; i <= maxx; i += 2)
	{
		prime[i] = 1;
	}
	for (int i = 3; i <= maxx; i += 2)
	{
		if (prime[i] == 1)
		{
            v.push_back(i);
			for (int j = i * i; j <= maxx; j += i)
			{
				prime[j] = 0;
			}
		}
	}
	// for (int i = 0; i <= maxx; ++i)
	// {
	// 	if (prime[i] == 1) v.pb(i);


	// }
	int n; cin >> n;
	cout << v[n - 1];



	return 0;
}


