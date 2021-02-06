#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define M 1000000007
using namespace std;
vector<vector<ll>> mul(vector<vector<ll>> &A,vector<vector<ll>> B){
    vector<vector<ll>> C(2,vector<ll>(2));
    for(int i = 0;i<2;i++){
        for(int j = 0;j<2;j++){
            for(int x = 0;x <2;x++){
                C[i][j] = ((C[i][j]%M) + (((A[i][x]%M) * (B[x][j]%M))%M))%M;
            }
        }
    }
    return C;
}
vector<vector<ll>> pow(vector<vector<ll>> &A,ll p){
    if(p==1)
        return    A;
    if(p&1)
        return    mul(A,pow(A,p-1));
    vector<vector<ll>>X = pow(A,p/2);

    return    mul(X,X);
}

ll fib(ll n){
    if(!n)
    return 0;
    if(n==1 or n==2){
        return 1;
    }
    vector<ll> F1(2);
    F1[0]=F1[1]=1;
    vector<vector<ll>>T(2,vector<ll>(2));
    T[0][0]=0;
    T[0][1]=T[1][0]=T[1][1]=1;
    T=pow(T,n-1);
    ll    res=0;
    for(int    i=0;i<2;i++){
        res=((res%M)+((T[0][i]%M)*(F1[i]%M))%M)%M;
    }
    return    res%M;
}

ll gcd(ll a,ll b){
    if(a==-1)
        return b;
    if(b==-1)
        return a;
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void buildTree(ll *inp,ll *tree,ll ss,ll se,ll index){
    if(ss==se){
        tree[index]=inp[ss];
        return;
    }
    ll mid=(ss+se)/2;
    buildTree(inp,tree,ss,mid,2*index);
    buildTree(inp,tree,mid+1,se,2*index+1);
    tree[index]=gcd(tree[2*index],tree[2*index+1]);
    return;
}

ll query(ll *tree,ll ss,ll se,ll qs,ll qe,ll index){
    if(ss>qe or se<qs)
        return -1;
    if(ss>=qs and se<=qe)
        return tree[index];
    ll mid=(ss+se)/2;
    ll lAns=query(tree,ss,mid,qs,qe,2*index);
    ll rAns=query(tree,mid+1,se,qs,qe,2*index+1);
    return gcd(lAns,rAns);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin >> n >> q;
    ll inp[n+1];
    ll tree[4*n+1];
    for(ll i = 1;i<=n;i++){
        cin >> inp[i];
    }
    buildTree(inp,tree,1,n,1);
    while(q--){
        ll qs,qe;
        cin >> qs >> qe;
        cout<<fib(query(tree,1,n,qs,qe,1))%M<<endl;
    }
    return 0;
}
