#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200000];
int child_count[100000];
int visited[123456];
long long happy=0;
vector<int>master;
set<int>s;
int node,edge;
void dfs(int x)
{
    visited[x]=-1;
    for(int i=0;i<adj[x].size();i++)
    {

        if(visited[adj[x][i]]==0)
        {
            dfs(adj[x][i]);
        }
    }

    visited[x]=1;
    s.insert(x);
//    cout<<x<<"\t";
}
void dfs2(int x,int y)
{

    visited[x]=-1;

    for(int i=0;i<adj[x].size();i++)
    {

        if(visited[adj[x][i]]==0)
        {
            dfs2(adj[x][i],x);
        }



    }

    visited[x]=1;
    if(x!=y)
    {
        if(child_count[x]>child_count[y])
            happy++;
    }
//    s.insert(x);
//    cout<<x<<"\t";
}
int main()
{
    cin>>node>>edge;

    for(int i=1;i<=edge;i++)
    {
        int node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
        //adj2[node2].push_back(node1);
        child_count[node1]++;
        child_count[node2]++;
//        parent[node2]=node1;
    }
    for(int i=1;i<=node;i++)
    {
        visited[i]=0;
    }

    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
            master.push_back(*s.begin());
            s.erase(s.begin(),s.end());
        }
    }
    for(int i=1;i<=node;i++)
    {
        vector<int>::iterator it;
        it=find(master.begin(),master.end(),i);
        if(it==master.end())
            child_count[i]--;
    }

    for(int i=1;i<=node;i++)
    {
        visited[i]=0;
    }

    for(int i=0;i<master.size();i++)
    {
        if(visited[master[i]]==0)
        {
            dfs2(master[i],master[i]);
        }
    }
    cout<<happy<<endl;
    return 0;
}
