#include <iostream>
using namespace std;
void multiply(int *a,int &n,int no)
{
    int carry=0;
    for(int i=0;i<n;i++)
    {
        int product=a[i]*no + carry;
        a[i]=product%10;
        carry=product/10;
    }
    while(carry)
    {
        a[n]=carry%10;
        carry=carry/10;
        n++;
    }
}
void bigFactorial(int numbers)
{
    int *a=new int[10000];
    for(int i=0;i<10000;i++)
    {
        a[i]=0;
    }
    a[0]=1;
    int n=1;
    for(int i=1;i<=numbers;i++)
    {
        multiply(a,n,i);
    }
    //print the result
    for(int i=n-1;i>=0;i--)
    {
        cout<<a[i];
    }
    delete[] a;
    return;
}
int main()
{
    int n;
    cin>>n;
   bigFactorial(n);
   return 0;
}
