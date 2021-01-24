#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
        int slen = s.length(),plen = p.length();
        int idx1 = 0,idx2 = 0;
        int stInd = -1,Tmpidx = -1;
        while(idx1 < slen)
        {
            if(idx2<plen && (p[idx2]=='?' || p[idx2]==s[idx1]))
            {
                idx1++;
                idx2++;
            }
            else if(idx2 < plen && p[idx2] == '*')
            {
                stInd = idx2;
                Tmpidx = idx1;
                idx2++;
            }
            else if(stInd == -1)
                return false;
            else
            {
                idx1 = Tmpidx + 1;
                idx2 = stInd + 1;
                Tmpidx++;
            }
        }

        for(int i=idx2;i<plen;i++)
            if(p[i]!='*')
                return false;
        return true;
    }
int main() {
    string s,p;
    cin>>s>>p;
    if(isMatch(s,p)){
        cout<<"MATCHED";
    }
    else{
        cout<<"NOT MATCHED";
    }
}
