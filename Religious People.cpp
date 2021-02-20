#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
class Graph
{
private:
    ll V;
    map<ll, list<ll>> adjList;
public:
    Graph(ll v)
    {
        V = v;
    }
    void addEdge(ll u, ll v)
    {
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(ll node, map<ll, bool> &visited)
    {

        visited[node] = true;

        for (ll child : adjList[node])
        {
            if (!visited[child])
            {
                dfsHelper(child, visited);
            }
        }
    }

    ll dfsReligiousPeople(ll src, ll a, ll b)
    {

        //If cost of constructing temples in each city is less than repairing roads , simply build temples in all cities
        if (a <= b)
        {
            return V * a;
        }

        map<ll, bool> visited;
        ll components = 1;
        dfsHelper(src, visited);

        for (auto i : adjList)
        {
            ll city = i.first;
            if (!visited[city])
            {
                dfsHelper(city, visited);
                components++;
            }
        }

        ll n = adjList.size();
        ll totalCost = a * components + b * (n - components) + a * (V - n);

        return totalCost;
    }
};

int main()
{
    ll testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll n; //No of cities (nodes)
        ll m; //No of roads  (edges)
        ll a; //Cost to construct a temple
        ll b; //Cost to repair a road

        cin >> n >> m >> a >> b;

        Graph g(n);
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        //  g.printAdjList();

        cout << g.dfsReligiousPeople(1, a, b) << endl;
    }

    return 0;
}
