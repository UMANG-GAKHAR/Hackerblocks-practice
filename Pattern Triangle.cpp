#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		for(int space=1;space<=n-i;space++)
		{
			cout<<" \t";
		}
		int val=i;
		for(int cnt=1;cnt<=i;cnt++) {
			cout<<val<<"\t";
			val=val+1;
		}
		val=val-2;
		for(int cnt=1;cnt<=i-1;cnt++) {
			cout<<val<<"\t";
			val=val-1;
		}
		cout<<endl;
	}
	return 0;
}
