#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define F               first
#define S               second
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define endl            '\n'
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define forI(i,a,n)       for(int i=a;i<=n;i++)
#define forD(i,a,n)       for(int i=n;i>=a;i--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void init(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
unordered_map<string, int> beverage;
map<int, string> revbeverage;
vector<int> g[1005];
void topSort(int n){
    int inDeg[n] = {0};
    vi ans;

    forI(i, 0, n-1){
        for(auto nbr : g[i])
            inDeg[nbr]++;
    }

    multiset<int> q;
    forI(i, 0, n-1)   if(inDeg[i] == 0)   q.insert(i);
    while(!q.empty()){
        int node = *q.begin();
        q.erase(q.begin());
        ans.pb(node);

        for(auto nbr : g[node]){
            inDeg[nbr]--;
            if(inDeg[nbr] == 0){
                q.insert(nbr);
            }
        }
    }

    forI(i, 0, n-1){
        cout<<revbeverage[ans[i]];
        if(i != n-1)    cout<<' ';
    }
    cout<<'.';

}
void solve(int n){
    string b, b1;
    forI(i, 0, n-1){
        cin>>b;
        beverage[b] = i;
        revbeverage[i] = b;
    }
    int m;  cin>>m;
    forI(i, 1, m){
        cin>>b>>b1;
        g[beverage[b]].pb(beverage[b1]);
    }
    topSort(n);
	beverage.clear();
	revbeverage.clear();
	for(int i=0;i<1005;i++){ g[i].clear();  }
}
int32_t main(){
    init();

    int n, t=1;
    while(cin>>n){
        cout<<"Case #"<<t<<": Vivek should drink beverages in this order: ";
        solve(n);
        cout<<endl;
        t++;
    }
    return 0;
}
