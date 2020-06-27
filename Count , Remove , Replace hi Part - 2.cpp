#include<iostream>
#include<cstring>
using namespace std;
int ans=0;
//Function to count number of hi which is not follow by t.
void count(char arr[],int n){
    if(n==0){return;}
    count(arr,n-1);
    if(arr[n-1]=='i'&&arr[n-2]=='h'&&arr[n]!='t'){
        ans++;
    }
}

//Function which replace hi to bye
void print1(char arr[],int n,int size){
    if(n==0){return;}
    print1(arr,n-1,size);
    if(arr[n-1]=='h'&&arr[n]=='i'&&arr[n+1]!='t'){
        cout<<"bye";
    }
    else if(arr[n-1]=='i'&&arr[n-2]=='h'&&arr[n]!='t'){
    }
    else{
        cout<<arr[n-1];
    }
}

//Function which remove hi from given strings
void print2(char arr[],int n,int size){
    if(n==0){return;}
    print2(arr,n-1,size);
    if(arr[n-1]=='h'&&arr[n]=='i'&&arr[n+1]!='t'){
    }
    else if(arr[n-1]=='i'&&arr[n-2]=='h'&&arr[n]!='t'){
    }
    else{
        cout<<arr[n-1];
    }
}
int main() {
    char arr[100];
    cin>>arr;
    int n=strlen(arr);
    count(arr,n);
    cout<<ans<<endl;
    print2(arr,n,n);
    cout<<endl;
    print1(arr,n,n);
    cout<<endl;
    return 0;
}
