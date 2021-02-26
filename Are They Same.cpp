#include<bits/stdc++.h>
using namespace std;
bool fun(string s1,string s2)
{
    string a1,a2,b1,b2;
        if(s1==s2)
            return true;//cout<<"YES"<<endl;
		else if(s1.length()!=s2.length())
		{
			return false;
		}
		else if(s1.length()==1)
		    return false;
		else
		{
            int len = s1.length();
            if(len%2==1)
                return false;
            int half = (len+1)/2;
            a1=s1.substr(0,half);
            a2=s1.substr(half,len-half);
            b1=s2.substr(0,half);
            b2=s2.substr(half,len-half);
			
            if((fun(a1,b2) && fun(a2,b1)) or (fun(a2,b2) && fun(a1,b1)))
                return true;//cout<<"YES"<<endl;
            else return false;// cout<<"NO"<<endl;

		}
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
        if(fun(s1,s2))
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
		
	}
}
