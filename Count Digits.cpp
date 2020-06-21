#include<iostream>
using namespace std;
int main() {
	int r,n,key,i;
    i=0;
	cin>>n;
	cin>>key;
	while(n>0)
	{
		r=n%10;
		 if(r==key)
		{
			i++;
		}
		n=n/10;
	}
	cout<<i;
	return 0;
}
