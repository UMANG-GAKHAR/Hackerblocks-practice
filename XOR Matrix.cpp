#include <iostream>
using namespace std;
int n,a[555][555],b[555],i,j,m,x;
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) cin>>a[i][j];
        x^=a[i][0];
        b[i]=1;
    }
    if(!x){
        for(i=0;i<n;i++)
            for(j=1;j<m;j++)
                if(a[i][j]!=a[i][0]) {b[i]=j+1; j=m; i=n; x=1;}
    }
    if(!x) {cout<<"NIE"; return 0;}
    cout<<"TAK\n";
    for(i=0;i<n;i++) cout<<b[i]<<" ";
    return 0;
}
