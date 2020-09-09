#include <iostream>
#include<cmath>

using namespace std;

int main()
{
        int roota,rootb;
int a,b,c;
cin>>a>>b>>c;
roota = ((-b+sqrt((b*b) -(4*a*c))) /(2*a));
rootb = ((-b-sqrt((b*b) -(4*a*c))) /(2*a));
if  (  (a!=0)&&(b*b-4*a*c ==(0))) //real and equal roots
cout<<roota<<rootb;
if(((b*b) -4*a*c)>0 &&(a!=0))//real and district
cout<<max(roota,rootb)<<" "<<min(roota,rootb);

return 0;
}
