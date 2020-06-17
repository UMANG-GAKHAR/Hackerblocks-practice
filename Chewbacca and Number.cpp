#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i=0;
    if(s[i]=='9'){
        i++;
    }
    for(;s[i]!='\0';i++){
        int digit=s[i]-'0';
        // digit=9-digit;
        if(digit>=5){
            digit=9-digit;
        }
        s[i]=digit+'0';
    }
    cout<<s<<endl;
    return 0;
}
