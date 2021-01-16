#include<bits/stdc++.h>
using namespace std;
class Graph {
private:
	map<long long int, list<long long int>> adjList;
public:
	Graph(long long int n)
	{
		for (long long int i = 1; i <= n; i++)
		{
			adjList[i].push_back(0);
		}
	}
	void addEdge(long long int u, long long int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	void bfsShortestPath(long long int src, long long int n, long long int m)
	{
		queue<long long int>q;
		map<long long int, long long int>distance;
		map<long long int, bool>visited;
		for (long long int i = 1; i <= n; i++)
		{
			distance[i] = -1;
		}
		q.push(src);
		distance[src] = 0;
		while (q.empty() == false)
		{
			long long int temp = q.front();
			q.pop();
			for (auto element : adjList[temp])
			{
				if (distance[element]==-1)
				{
					distance[element] = distance[temp] + 1;
					q.push(element);
				}
			}
		}
		for(long long int i=1;i<=n;i++){
			if(i!=src){
            	cout<<(distance[i]==-1?(-1):(distance[i]*6))<<" ";
			}
		}
        cout<<endl;
	}
};

int main()
{
	long long int q;
	cin >> q;
	while (q--)
	{
		long long int n, m;
		cin >> n >> m;
		Graph g(n);
		for (long long int i = 0; i < m; i++)
		{
			long long int u, v;
			cin >> u >> v;
			g.addEdge(u, v);
		}
		long long int src;
		cin >> src;
		g.bfsShortestPath(src, n, m);
	}
	return 0;
}
