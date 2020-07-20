#include<iostream>
using namespace std;

void primeseive(int arr[],int cs[]){
	for(int i=3;i<=1000000;i+=2){
		arr[i]=1;
	}
	for(int i=3;i<=1000000;i+=2){
		if(arr[i]==1){
			for(int j=2*i;j<=1000000;j+=i){
				arr[j]=0;
			}
		}
	}
	arr[2]=1;
	arr[0]=arr[1]=0;
	for(int i=2;i<=1000000;i++){
		cs[i]=cs[i-1]+arr[i];
	}

}
int main() {
int primearr[1000000]={0};int cs[1000000]={0};
primeseive(primearr,cs);int t,a,b;


cin>>t;
int noprime;
while(t--){
	cin>>a>>b;
	noprime=cs[b]-cs[a-1];
	cout<<noprime<<"\n";
}

	return 0;
}
