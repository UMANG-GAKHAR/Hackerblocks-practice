#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N1, N2;
	cin>>N1;
	cin>>N2;
	int i=1;
	int kk=0;
	while(i)
	{
		int num = (3*i)+2;
		if((num%N2)!=0)
		{
			cout<<num<<endl;
			kk++;
			if(kk==N1)break;
		}
		i++;
	}
	return 0;
}


