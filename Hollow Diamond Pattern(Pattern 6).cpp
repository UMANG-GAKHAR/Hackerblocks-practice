#include <iostream>
using namespace std;
int main() 
{
    int N;
    cin>>N;
    int m=(N+1)/2;
    int ie, je;
    if (N%2!=0 && N>0 && N<10)
    {
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i<=m)
            {
                ie=i;
                //cout<<" ";
            }
            else
           {
               ie=N-i+1;
               //cout<<" ";
           }
           if(j<=m)
           {
               je=j;
           }
           else
           {
               je=N-j+1;
           }
         if(ie+je<=m+1)
         {
             cout<<"*\t";
         }
         else
         {
             cout<<" \t";
         }
        }
        cout<<endl;
    }
}
}
