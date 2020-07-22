#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long   ////////////////////////////////////////////////////////////////
using namespace std;

int main(){


		int n,t;

		cin>>t;

		while(t--){
		vector<int>v1;  //////////////////////////////////////////////
		//vector<int>v2;
		cin>>n;

		for(int i=0; i<n; i++)
		{

			int no;

			cin>>no;

			v1.push_back(no);
		}

		sort(v1.begin(),v1.end());


		ll int maxx=0;

		for(int j=0; j<n/2; j++){

			maxx+=abs(v1[j]-v1[n-j-1]);

		}

		//cout<<maxx<<endl;  ////////////////////////////////////////////////////////////////////////////////

		ll int minn=0;

		for(int i=0; i<n-1; i+=2){  ///////////////////////////////////////////////////

			minn+=abs(v1[i]-v1[i+1]);

		}

		cout<<minn<<" "<<maxx<<endl;  ///////////////////////////////////////////////////////////////////////////

	}


	return 0;
}
