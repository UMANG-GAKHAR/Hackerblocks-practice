#include<iostream>
using namespace std;
int main(){
    int n;

     cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        if(i==1 or i==n)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<"*";
            }


        }
        else{

            cout<<"*";
            for(int j=1;j<n-2;j++)
            {
                cout<<" ";
            }
            cout<<" *";
        }
        cout<<endl;

    }

}
