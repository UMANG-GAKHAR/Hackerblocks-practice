#include<iostream>
#include<string>
using namespace std;
int main()
{     
    int maxm=-1;
    char res;
    char freq[256]={0};
	char str[1000];

	cin>>str;
	for(int i=0;str[i]!='\0';i++)
	{
		freq[str[i]]++;
		
	}
	for(int i=0;str[i]!='\0';i++)
	{
		if(maxm < freq[str[i]])
		{
            maxm = freq[str[i]];
			res=str[i];
			
		}
	}
	cout<<res<<endl;
	
	return 0;
}
