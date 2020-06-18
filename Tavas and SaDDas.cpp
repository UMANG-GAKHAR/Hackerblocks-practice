#include <iostream>
using namespace std;
#define int long long

//total numbers of (count) digit numbers below n
int Digit(int n,int count)
{
    int ans2=0,t,p=1;
   while(n!=0)
    {
        t=n%10;
        if(t==7)
        {
            ans2=ans2 + p;
            p=p*2;
            n=n/10;
        }
        else if(t==4)
        {
            p=p*2;
            n=n/10;
        }
    }
    return ans2;
}

void calc(int n,int count){
	string str=to_string(n);
	int ans=0;
	for(int i=0;i<count;i++){
		if(str[i]=='4')	ans+=(1<<(count-i-1));
		else ans+=(2*(1<<(count-i-1)));
	}
	cout<<ans<<endl;
}



signed main() {
    int n;
    cin>>n;
    int count = 0;
    //digits with lucky number
	int k=n;
    while(k!=0)
    {
        if(k%10==4 || k%10 == 7)
        k=k/10;
        count++;
    }
    //total number of digits
    int count1=0;
	k=n;
    while(k!=0)
    {
        k=k/10;
        count1++;
    }
    //if count=count1 that means all digits are lucky numbers
    if(count==count1)
    {
	
        calc(n,count);
       
    }
    else
        cout<<"error";
    
    return 0;
}
