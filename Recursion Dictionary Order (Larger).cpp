#include<bits/stdc++.h>
using namespace std;

vector<string>result;
void permute(string s,string output,int i)
{
	//base case
	if(s[i] == '\0')
    {
	   if(s>output)
       {
          result.push_back(s);
       }
       return;
	}
	//to find all the possible words
	for(int j=i; s[j] != '\0'; j++){
		swap(s[i],s[j]);
		//recursive case
		permute(s,output,i+1);
	}
}

int main()
{
	string s;
	cin>>s;
    string output;
    output=s;
	permute(s,output,0);
    sort(result.begin(),result.end());//Sorting the outputs
    for(int i=0;i<result.size();i++)
    cout<<result[i]<<endl;
	return 0;
}
