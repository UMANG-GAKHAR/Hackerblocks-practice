#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
const int N = 3000;
const int W = 1e5;
const int INF = 1e9;
vector<pair<int, int>> g[N];
int dist[N];
bool visited[N];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        assert(2 <= n && n <= N);
        assert(1 <= m && m <= 1LL * n * (n - 1) / 2);
        for(int i = 0; i < n; ++i) g[i].clear();
        for(int i = 0; i < m; i++)
        {
            int v, u, w;
            scanf("%d %d %d", &v, &u, &w);
            assert(1 <= v && v <= n);
            assert(1 <= u && u <= n);
            assert(1 <= w && w <= W);
            --v; --u;
            g[v].push_back({u, w});
            g[u].push_back({v, w});
        }
        int s;
        scanf("%d", &s);
        --s;

        fill(dist, dist + n, INF);
        fill(visited, visited + n, 0);
        dist[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, s});
        while(!q.empty())
        {
            int v = q.top().second;
            int d = q.top().first;
            q.pop();
            if(visited[v]) continue;
            visited[v] = 1;
            for(auto it: g[v])
            {
                int u = it.first;
                int w = it.second;
                if(dist[v] + w < dist[u])
                {
                    dist[u] = dist[v] + w;
                    q.push({dist[u], u});
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(i == s) continue;
            printf("%d ", (dist[i] != INF ? dist[i] : -1));
        }
        printf("\n");
    }
    return 0;
}
