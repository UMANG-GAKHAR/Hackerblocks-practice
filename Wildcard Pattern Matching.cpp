#include <iostream>
#include<vector>
using namespace std;

 int wildcard_matching(string &str,string &pat,int i,int j,vector<vector<bool>> &dp){
     int res=0;
     if(str[i]=='\0' or pat[j]=='\0'){ //* Correctly check the base cases.
         if(str[i]=='\0' and pat[j]=='\0') return 1;
         return 0;
     }
     //look up
     if(dp[i][j]!=0){
         return dp[i][j];
     }
    if(str[i]==pat[j]){
        res=wildcard_matching(str,pat,i+1,j+1,dp);
    }
    else{
        if(pat[j]=='?'){
            res=wildcard_matching(str,pat,i+1,j+1,dp);
        }
        else if(pat[j]=='*'){
            res=(wildcard_matching(str,pat,i,j+1,dp) or 
				wildcard_matching(str,pat,i+1,j+1,dp) or
				wildcard_matching(str,pat,i+1,j,dp)); //* One case was not considered
        }
        else{
            res=0;
        }
    }
    return dp[i][j]=res;
 }
 int main() {
   string str;
   string pat;
   cin>>str;
   cin>>pat;
   vector<vector<bool>> dp(str.length()+1,vector<bool>(pat.length()+1,0)); //* Use exact size vector as required, because memory constraints are tight.
   cout<<wildcard_matching(str,pat,0,0,dp);
}
