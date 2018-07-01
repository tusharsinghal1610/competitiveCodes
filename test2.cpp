#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[300005];
struct query{
	ll l;
	ll r;
	ll i;
}q[200005];
ll answer=0;
//vector <ll> cnt(1000005,0);
unordered_map <int,int> cnt;
ll block;
/*bool comp(query i,query j){
	if(i.l==j.l){
	return i.r<j.r;
    }
    return i.l<j.l;
	
}*/

bool comp(query x, query y)
{
    // Different blocks, sort by block.
    if (x.l/block != y.l/block)
        return x.l/block < y.l/block;
 
    // Same block, sort by R value
    return x.r < y.r;
}


void add(ll cur){
	
	cnt[a[cur]]++;
	if(cnt[a[cur]]==1){
		answer++;
	}
}
void remove(ll cur){
	
	cnt[a[cur]]--;
	if(cnt[a[cur]]==0){
		answer--;
	}
}
int main(){
	ll temp;
	scanf("%lld",&n);
	block = (ll)sqrt(n);
	for(ll i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	ll dq,l,r;
	scanf("%lld",&dq);
	for(ll i=0;i<dq;i++){
		scanf("%lld",&l);
        scanf("%lld",&r);
		q[i].l=l;
		q[i].r=r;
		q[i].i=i;
	}
	sort(q,q+dq,comp);
	vector <ll> ans(dq);
	ll curl=0,curr=0;
	for(ll k=0;k<dq;k++){
		
		l=q[k].l-1;
		r=q[k].r-1;
		
		while(curl<l){
			cnt[a[curl]]--;
	if(cnt[a[curl]]==0){
		answer--;
	}
			curl++;
		}
		while(curl > l){
			cnt[a[curl-1]]++;
	if(cnt[a[curl-1]]==1){
		answer++;
	}
			curl--;
		}
		while(curr<=r){
			cnt[a[curr]]++;
	if(cnt[a[curr]]==1){
		answer++;
	}
			curr++;
		}
		while(curr>r+1){
		cnt[a[curr-1]]--;
	if(cnt[a[curr-1]]==0){
		answer--;
	}
			curr--;
		}
		ans[q[k].i]=answer;
	}
	for(ll i=0;i<dq;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
	
}
