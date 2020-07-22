#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Graph{
    public:
    map<ll, list<ll>> adjList;
    vector<int> vis;
    Graph(ll n) {
        vis.reserve(n);
        for (int i = 0; i < n; i++) {
            vis[i] = false;
        }
    }
    void insertEdge(ll x, ll y) {
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    ll dfs(ll src) {
        vis[src] = true;
        ll cnt = 0;
        for (auto nbr: adjList[src]) {
            if (!vis[nbr]) {
                cnt += dfs(nbr);
            }
        }
        return cnt+1;
    }
};
int main() {
    ll n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--) {
        ll x, y;
        cin >> x >> y;
        g.insertEdge(x, y);
    }
    vector<ll> components;
    for (int i = 0; i < n; i++) {
        if (!g.vis[i]){
            ll val = g.dfs(i);
            components.push_back(val);
        }
    }
    ll ans = 0;
    for (int i = 0; i < components.size(); i++) {
        for (int j = i+1; j < components.size(); j++) {
            ans += components[i]*components[j];
        }
    }
    cout << ans;
    return 0;
}
