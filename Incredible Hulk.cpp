#include<iostream>
using namespace std;
int countbitsfast(int n)
{
	int ans=0;
	while(n>0)
	{
		n=n &  (n-1);
		ans++;
	}
	return ans;
}

int main() {
	int n;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<countbitsfast(n)<<endl;
	}
	return 0;
}
