#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> s;
    long q ;
    cin>>q;
    while(q--){
        int queryType;
        cin>>queryType;
        if(queryType == 1){
            if(s.empty()){
                cout<<"No Code";
            }
            else {
                cout<<s.top();
                s.pop();
            }
            cout<<endl;
        }
        else {
            int cost ;
            cin>>cost;
            s.push(cost);
        }
    }    

    return 0;
}
