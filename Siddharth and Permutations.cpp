# include <bits/stdc++.h>
using namespace std;
# define fi cin
# define fo cout
# define x first
# define y second
# define IOS ios_base :: sync_with_stdio(0)
int a[1 << 20];
int b[1 << 20];
pair < int , int > t[1 << 22];
void build(int p,int u,int node)
{
    if (p == u) t[node] = {b[p],p};
    else
    {
        int m = (p + u) / 2;
        build(p,m,node << 1);
        build(m+1,u,node << 1 | 1);
        t[node] = max(t[node << 1],t[node << 1 | 1]);
    }
}
// building the tree 
void Del(int p,int u,int v,int node)
{
    if (p == u) t[node] = {0,p};
    else
    {
        int m = (p + u) / 2;
        if (v <= m) Del(p,m,v,node << 1);
        else Del(m+1,u,v,node << 1 | 1);
        t[node] = max(t[node << 1],t[node << 1 | 1]);
    }
}
// deleting a visited vertex
pair < int , int > query(int p,int u,int l,int r,int node)
{
    if (l > r) return {0,0};
    if (l <= p && u <= r) return t[node];
    int m = (p + u) / 2;
    pair < int , int > ans = {0,0};
    if (l <= m) ans = max(ans,query(p,m,l,r,node << 1));
    if (m+1<=r) ans = max(ans,query(m+1,u,l,r,node << 1 | 1));
    return ans;
}
// find edge for a fixed interval
int was[1 << 20];
// visited/not
int n;
vector < int > Sort;
//sorted graph
void dfs(int node)
{
	//node = i from tutorial
    Del(1,n,node,1);
    was[node] = 1;
    if (b[node] != n + 1 && !was[b[node]]) dfs(b[node]);
    //edges of first type
    while (1)
    {
        auto it = query(1,n,1,a[node] - 1,1);
        //it.y = j from tutorial,it.x is b[j]
        if (it.x > node) dfs(it.y);//there is edge
        else break;//there aren't remaining
    }
    //edges of second type
    Sort.push_back(node);
}
int ans[1 << 20];
int main(void)
{
    scanf("%d\n",&n);
    for (int i = 1;i <= n;++i) b[i] = n + 1;
    for (int i = 1;i <= n;++i) scanf("%d",&a[i]);
    for (int i = 1;i <= n;++i)
        if (a[i] != -1)
            b[a[i]] = i;
    //b from tutorial
    for (int i = 1;i <= n;++i)
        if (a[i] == -1)
            a[i] = n + 1;
    //just replacing
    build(1,n,1);
    //building the tree
    for (int i = 1;i <= n;++i)
        if (!was[i])
            dfs(i);
    //sorting the graph
    int cnt = 0;
    for (auto it : Sort)
        ans[it] = ++cnt;
    //assigning p[ans[i]] = i as stated in tutorial
    for (int i = 1;i <= n;++i)
        printf("%d%c",ans[i]," \n"[i == n]);
    //printing one possible permutation
    return 0;
}
