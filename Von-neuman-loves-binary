#include <iostream>
using namespace std;
int binarytodecimal( int num)
{
int i =0;
int ans = 0;
while( num != 0)
{

int rem = num % 10;
num = num / 10;
ans += rem*pow(2,i);
i++;
}
return ans;
}
int main()
{
int n;
cin>>n;
while(n!=0)
{
int num;
cin>>num;
int p = binarytodecimal(num);
cout<<p<<endl;
n–;
}
return 0;
}
