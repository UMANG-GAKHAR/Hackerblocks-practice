#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int count = 0;
	for (int i = 0; i < n-1; ++i)
	{
		for(int j=i+1;j<n;j++){
			if((a[i]&a[j])==0){
				if(a[i]==a[j]){
					count+=1;
				}
				count+=2;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}
