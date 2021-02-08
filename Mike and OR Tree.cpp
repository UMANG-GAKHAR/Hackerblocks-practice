#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Graph{
    int n;
    vector<int>*adj;
    vector<int> dist;
public:
    Graph(int n){
        this->n=n;
        adj=new vector<int>[n+1];
        dist.reserve(n+1);
        for(int i=0;i<=n;i++){
            dist[i]=INT_MAX;
        }
    }
    void addEdge(int a,int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
        return ;
    }

    void dfsUpdate(int src,int level,int parent){
        if(dist[src]>level){
            dist[src]=level;
        }else{
            return;
        }
        for(int x:adj[src]){
            if(x==parent){continue;}
            dfsUpdate(x,level+1,parent);
        }
        return ;
    }
    int query(int src){
        return dist[src];
    }

};

int main(){
    int n,q;
    cin>>n>>q;
    Graph G(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        G.addEdge(a,b);
    }
    G.dfsUpdate(1,0,-1);
    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==0){
            cout<<G.query(b)<<endl;
        }else{
            G.dfsUpdate(b,0,-1);
        }
    }
    return 0;
}
