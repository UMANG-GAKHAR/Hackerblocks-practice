#include<iostream>
using namespace std;
int main()
{
	//array size was wrongly declared
    int m,n,i,j,a[1000][1000];
	cin>>m>>n;
    //val of row and col were interchanged
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

    //for loop to go through all the columns was missing
    for(int j=0;j<n;j++)
    {
        //odd even check was interchanged
        if((j%2)==0)
        {   for(int i=0;i<m;i++)
                cout<<a[i][j]<<", ";
        }
        else
        {
            for(int i=m-1;i>=0;i--)
                cout<<a[i][j]<<", ";
        }
    }
    cout<<"END";
	return 0;

}
