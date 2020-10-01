#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		cin>>a[i][j];
		}
	}
	int search;
	cin>>search;
	int i=0 , j=m-1;bool found=false;

	while(i>=0&&j>=0&&i<n&&j<m)
	{
     if(a[i][j] ==search)
     {
         found=true;
		 cout<<1;break;
	 }
	 if(a[i][j] < search)
	 i++;
     else
	 j--;
	}
    
    if(!found)
	cout<< 0;
	return 0;
}
