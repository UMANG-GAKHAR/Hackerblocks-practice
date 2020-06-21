#include<iostream>
using namespace std;
int main() {
	
	int min_fernehite=0;
	cin>>min_fernehite;
	
	int max_fernehite;
	cin>>max_fernehite;
	
	int no;cin>>no;
	
	int c;
	
	while(min_fernehite<=max_fernehite){
		c=(5*(min_fernehite-32))/9;
		cout<<min_fernehite<<" "<<c;
		cout<<"\n";
		min_fernehite+=no;
	}

	return 0;
}
