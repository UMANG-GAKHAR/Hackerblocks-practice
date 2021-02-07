#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
#define ll long long int
#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)

#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

// TRY SOLVING IT AGAIN NEXT TIME AND MUST LOOK AT THE EDITORIAL  SOLUTION

vector<vector<int> >ans;
set<vector<int> > mp;
int B;

void solve(vector<int> &A,int i,int req,vector<int> st){
    if(i>A.size() or req<0)return ;

    if(req==0){
        if(!st.empty() and mp.find(st)==mp.end()){
            mp.insert(st);
            ans.push_back(st);
        }
    }

    if(i==A.size())return;

    st.push_back(A[i]);
    solve(A,i+1,req-A[i],st);
    st.pop_back();

    solve(A,i+1,req,st);

    vector<int> st2;
    st2.push_back(A[i]);
    solve(A,i+1,B-A[i],st2);
}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
    ans.clear();
    mp.clear();
    ::B=B;
    if(A.size()==0 or B==0)return ans;
    sort(A.begin(),A.end());
    vector<int> st;
    solve(A,0,B,st);
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
    int t=1;
    //s(t);
    while(t--){
        int n;
        cin>>n;
        vector<int>ar(n);
        F(i,0,n-1)cin>>ar[i];
        int t;
        cin>>t;
        vector<vector<int>> ans = combinationSum(ar,t);
        for(auto vec:ans){
            for(int num:vec){
                cout<<num<<" ";
            }
            cout<<endl;
        }
    }
}
