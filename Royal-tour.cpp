#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll int, list<ll int> > mi;
ll int id[100001]={0};
ll int stat[100001]={0};
ll int dp[100002][22];
ll int n;
vector<ll int> topo;
void topsort()
{ queue<ll int> q;
	for(ll int i=1;i<=n;i++)
	{if(id[i]==0)
		{q.push(i);
        topo.push_back(i);
		}

	}
	while(!q.empty())
	{ll int d=q.front();
		q.pop();
		for(auto i: mi[d])
		{id[i]--;
			if(id[i]==0)
			{q.push(i);
             topo.push_back(i); 
			}

		}

	}
return;


}
int main()
{
	#ifndef ONLINE_JUDGE
     freopen("inh.txt",  "r",  stdin);
     freopen("ouh.txt", "w", stdout);
    #endif
     ll int m;
          cin>>n>>m;
     for(ll int i=1;i<=n;i++)
     	cin>>stat[i];
     while(m--)
     {ll int a,b;
     	cin>>a>>b;
     	mi[a].push_back(b);
     id[b]++;}
topsort();
// for(auto i: topo)
 //cout<<i<<" ";  

ll int ans=0;
for(auto i : topo)
{
dp[i][stat[i]]++;
ans=max(ans,dp[i][stat[i]]);
for(auto j : mi[i])
{
for(ll int k=1;k<=21;k++)
{dp[j][k]=max(dp[j][k],dp[i][k]);
ans=max(ans,dp[j][k]);
}

}


}


cout<<ans;


}
