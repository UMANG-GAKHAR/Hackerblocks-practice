#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
class DSU{
    int *parent;
    int *rank;
    public:
    DSU(int n)
    {
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int i)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        //Otherwise
        return parent[i]=find(parent[i]);
    }
    //Unite(union)
    void unite(int x,int y)
    {
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2)
        {
            //Union by rank
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]=rank[s2]+rank[s1];

            }
            else
            {
                parent[s2]=s1;
                rank[s1]=rank[s1]+rank[s2];
            }
            
        }

    }
};
class Graph
{
    vector<vector<int>>edgelist;
    int v;
    public:
    Graph(int v)
    {
        this->v=v;

    }
    void addEdge(int x,int y,int w)
    {
        //We are pushing w first becuase the sorting to be done is on the basis of first parameter
        edgelist.push_back({w,x,y});

    }
    int kruksal_mst()
    {
        //Main Logic
        //Sort all the edges based upon weight
        sort(edgelist.begin(),edgelist.end());

        //Init a DSU
        DSU s(v);
        int ans=0;
        for(auto edge:edgelist)
        {
            //Take the edge in MST if it does not form a cycle
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            if(s.find(x)!=s.find(y))
            {
                s.unite(x,y);
                ans=ans+w;
            }
        }
        return ans;

    }
};
int main()
{
    /*Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);8*/
    int n,m;
    cin>>n>>m;
    //Graph containing  n nodes
    Graph g(n);
    //For each edge Taking the input
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        //We are subracting -1 because we are using 0 based indexing
        g.addEdge(x,y,w);
        //g.addEdge(x-1,y-1,w);
    }
    cout<<g.kruksal_mst()<<endl;
    return 0;
}
