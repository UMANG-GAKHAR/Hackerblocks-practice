#include<bits/stdc++.h>
using namespace std;
int	calculateMex(unordered_set<int>Set) {
	int	Mex	=0;
	
	while(Set.find(Mex)!=Set.end())								
	Mex++;
	return Mex;
}
int	calculateGrundy(int	n){
	if(n==0 || n==1)
		return 0;

	unordered_set<int>Set;

	for	(int i=1;i<n;i++){
		if(n%i==0){												
			Set.insert(calculateGrundy(i));
		}
	}
	return calculateMex(Set); 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		if(n%2==0)
		{
			cout<<2<<endl;
		}
		else{
			int ans=calculateGrundy(m);
			if(ans==0)
			cout<<2<<endl;
			else
			cout<<1<<endl;
		}
	}
}
