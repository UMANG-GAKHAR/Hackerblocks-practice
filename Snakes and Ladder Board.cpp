#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
	map< T, list<T > > l;
public:
	void addedge(T u,T v){
		l[u].push_back(v);
	}

	void bfs(T src,T dest){
		map< T, int > dist;
        queue<T> q;
        //visited[src]=0;
        for(int i=1;i<=110;i++){
            dist[i]= -1;
        }
        q.push(src);
        dist[src]=0;
        while(!q.empty()){

                T node= q.front();
                q.pop();
                for(auto nbr:l[node]){
                    if(dist[nbr]==-1){
                        q.push(nbr);
                        dist[nbr]= dist[node]+1;
                    }
                }
        }
        cout<<dist[dest]<<"\n";
	}
};

int main(){

    int t,n,m,u,v;
    cin>>t;
    while(t--){

            // input
        int board[110]={0};
        cin>>n;
        while(n--){
            cin>>u>>v;
            board[u]+= (v-u);
        }
        cin>>m;
        while(m--){
            cin>>u>>v;
            board[u]-= (u-v);
        }
        Graph<int> g;
        for( int i=1;i<101;i++){
            for(int dice=1;dice<=6;dice++){
                int j= i+dice;
                j+= board[j];

                if(j<=100){
                    g.addedge(i,j);
                }
            }
        }
        g.addedge(100,100);
        g.bfs(1,100);
    }
	return 0;
}
