#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)1e3+5
#define  sz(x) x.size()
#define  int long long int
#define  ld long double
#define  vi vector<int>
#define  vs vector<string>
#define  vc vector<char>
#define  mii map<int,int>
#define  pii pair<int,int>
#define  vpii vector<pii>
#define  test(x) while(x--)
#define  pb push_back
#define  eb emplace_back
#define  pq priority_queue
#define  mod 1000000007
#define  fo(i,a,n) for(int i=a;i<n;i++)
#define  rfo(i,n,a) for(int i=n;i>=a;i--)
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) begin(x),end(x)
#define  allr(x) rbegin(x),rend(x)
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k;
// vi adj[N];
// int vis[N],par[N],a[N];

int dp[N][N];

void go()
{
	cin>>n>>m;

	fo(i,0,m)
	{
		int x,y; cin>>x>>y;
		dp[x][y]++; // putting a gold at (i,j) of grid
	}

	fo(i,1,n+1)
	{
		fo(j,1,n+1)
		{
			dp[i][j] += dp[i][j-1]; // prefix sum of every row
		}
	}

	fo(i,1,n+1)
	{
		fo(j,1,n+1)
		{
			dp[i][j] += dp[i-1][j]; // prefix sum of every coloumn after taking prefix sum of every row
		}
	}


	int ans = -inf; // initialize ans with some minimum value

	fo(i,1,n)
	{
		fo(j,1,n)
		{
			ans = max(ans, min({ dp[i][j],  //  top left box sum
								 dp[n][j] - dp[i][j] , // bottom left box sum  - top left box sum
				                 dp[i][n] - dp[i][j] , // top right box sum - top left box sum 
				                 dp[n][n] - dp[n][j] - dp[i][n] +dp[i][j]
				               })  // bottom right box sum - bottom left box sum - top right box sum 
																				// plus the top left box sum because it get subtracted two times
			          );
			// db(ans);
			// 
		}
	}
	cout<<ans<<endl;


}

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t=1; 
	// cin>>t;
	test(t) go();
}
