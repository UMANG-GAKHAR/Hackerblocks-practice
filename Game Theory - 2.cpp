#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int output[1000005];
void findfactor(int n,vector<int>& v){
    v.push_back(1);
    for(int i=2;i<=sqrt(n);i++){
         if(n%i==0)
         {
             if(i==(n/i))
             {
                 v.push_back(i);
             }
             else
             {
                 v.push_back(i);
                 v.push_back(n/i);
             }
         }
    }
}
int mexnumber(set<int> s){
    int mex=0;
    while(s.find(mex)!=s.end())
        mex++;
    return mex;
}
int grundnumber(int n){
    if(n==1)
       return 0;
    if(output[n]!=-1)
       return output[n];
    vector<int> v;
    findfactor(n,v);
    set<int> s;
    for(int i=0;i<v.size();i++){
      s.insert(grundnumber(v[i]));
    }
    return output[n] = mexnumber(s);
}
void winnerofgame(int* arr,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=grundnumber(arr[i]);
    }
    if(ans!=0)
       cout<<"1"<<endl;
    else 
       cout<<"2"<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         memset(output,-1,sizeof(output));
         int* pilesize=new int[n];
         for(int i=0;i<n;i++)
            cin>>pilesize[i];
         winnerofgame(pilesize,n);
    }
    return 0;
}
