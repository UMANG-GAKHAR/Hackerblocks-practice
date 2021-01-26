#include<iostream>
#include<cmath>
using namespace std;
int main() {
	long long num;
	cin>>num;
	long long last=0;
	int p=0;
	while(num>0)
	{
		last+=(num%10)*pow(2,p);
		p+=1;
		num/=10;
	}
	cout<<last;
	return 0;
}
