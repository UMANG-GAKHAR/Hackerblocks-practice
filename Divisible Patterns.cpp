#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 1e9+7;

void computeLPSArray(string pat, int M, int* lps); 
 vector<int> ind;
void KMPSearch(string& pat, string& txt) 
{ 
    int M = pat.length(); 
    int N = txt.size(); 

    int lps[M]; 
    computeLPSArray(pat, M, lps); 

    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 

        if (j == M) { 
            ind.push_back(i-j);
            j = lps[j - 1]; 
        } 

        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 

void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; 

    lps[0] = 0; 

    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        { 
            if (len != 0) { 
                len = lps[len - 1]; 

            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int dp[10001][2520];

int fi(int pos,int rem){
    if(pos==ind.size())return (rem==0);
    int &res=dp[pos][rem];
    if(res!=-1)return res;
    res=0;
    res=fi(pos+1,(rem*ind[pos])%2520LL);
    res+=fi(pos+1,rem);
    res%=mod;
    return res;
}

signed main(){
    string pat,txt;
    cin>>pat>>txt;

    KMPSearch(pat,txt);
    for(int i=0;i<ind.size();i++){
        ind[i]=ind[i]+1;
    }
    memset(dp,-1,sizeof dp);

    int ans=fi(0,1);
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;

    return 0;
}
