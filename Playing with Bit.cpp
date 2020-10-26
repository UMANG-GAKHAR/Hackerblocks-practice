#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		int a,b;
		cin>>a>>b;
		unsigned int ans=0;
		for(int i=a; i<=b;i++)
		{
			int no=i;      /////////////////////////// dont change i as its req in the loop
			while(no>0)
			{
				if((no&1) == 1)
				{
					ans++;
					
				}
				no= (no>>1);         ////////////////////////////////////// outsie if loop otherwise tle
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
