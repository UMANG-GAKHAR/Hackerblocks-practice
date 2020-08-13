#include<iostream>
using namespace std;
int main() {
	int n; 
	cin>>n;
	int r;

	int no;
	while(n--){
		cin>>no;
		int even=0;
	int odd=0;
	while(no>0){
		r=no%10;
		no=no/10;
		if(r%2==0){
		even+=r;
        }
		else{
		odd+=r;
		}
	}
	if(even%4==0 || odd%3==0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
    }
	return 0;
}
