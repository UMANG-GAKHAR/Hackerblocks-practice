#include<bits/stdc++.h>
using namespace std;
struct node{
  long long a,b,c,d;
};
void buildtree(node *tr,node *arr,int idx,long long r,int s,int e){
   if(s>e)
     return ;
	 if(s==e){
        tr[idx]=arr[s];
		return;
	 }
	 int mid=(s+e)/2;
	 buildtree(tr,arr,2*idx,r,s,mid);
	 buildtree(tr,arr,2*idx+1,r,mid+1,e);
	 tr[idx].a=((tr[2*idx].a%r*tr[2*idx+1].a%r)%r+(tr[2*idx].b%r*tr[2*idx+1].c%r)%r)%r;
	 tr[idx].b=((tr[2*idx].a%r*tr[2*idx+1].b%r)%r+(tr[2*idx].b%r*tr[2*idx+1].d%r)%r)%r;
	 tr[idx].c=((tr[2*idx].c%r*tr[2*idx+1].a%r)%r+(tr[2*idx].d%r*tr[2*idx+1].c%r)%r)%r;
     tr[idx].d=((tr[2*idx].c%r*tr[2*idx+1].b%r)%r+(tr[2*idx].d%r*tr[2*idx+1].d%r)%r)%r;
}
node query(node *tr,int idx,long long r,int s,int e,int qs,int qe){
            if(s>e || e < qs || qe < s){
				return {1,0,0,1};
			}
			if(qs <= s && qe>=e){
				return tr[idx];
			}
			int mid=(s+e)/2;
			node one=query(tr,2*idx,r,s,mid,qs,qe);
			node two=query(tr,2*idx+1,r,mid+1,e,qs,qe);
			node trr;
	 trr.a=((one.a%r*two.a%r)%r+(one.b%r*two.c%r)%r)%r;
	 trr.b=((one.a%r*two.b%r)%r+(one.b%r*two.d%r)%r)%r;
	 trr.c=((one.c%r*two.a%r)%r+(one.d%r*two.c%r)%r)%r;
     trr.d=((one.c%r*two.b%r)%r+(one.d%r*two.d%r)%r)%r;
	 return trr;
}
int main() {
	long long r,n,q,l,rr;
	cin>>r>>n>>q;
	node tree[4*n+1];
	node arr[n];
	for(int i=0;i<n;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].c>>arr[i].d;
	}
    buildtree(tree,arr,1, r,0,n-1);
	while(q--){
     cin>>l>>rr;
	 node ans=query(tree,1,r,0,n-1,l-1,rr-1);
	 cout<<ans.a<<" "<<ans.b<<"\n"<<ans.c<<" "<<ans.d<<"\n";
	 cout<<"\n";
	}
	return 0;
}
