#include <bits/stdc++.h>
using namespace std;
int compareVersion(string version1, string version2) {
    int n1=version1.length(),n2=version2.length(),i=0,j=0;
    while(i<n1 || j<n2){
        int num1=0,num2=0;
        while(i<n1 && version1[i]!='.'){
            int num=version1[i]-'0';
            num1=num1*10+num;
            i++;
        }
        while(j<n2 && version2[j]!='.'){
            int num=version2[j]-'0';
            num2=num2*10+num;
            j++;
        }
        if(num1>num2){
            return 1;
        }
        else if(num1<num2){
            return -1;
        }
        else{
            i++;
            j++;
        }
    }
    return 0;
}

int main() {
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<compareVersion(s1,s2);
    return 0;
}
