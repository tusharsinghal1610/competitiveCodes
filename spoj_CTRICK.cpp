#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void update(ll *BIT, ll index,ll val,ll n){
	while(index<=n){
		BIT[index]+=val;
		index += (index & (-index));
	}
}
ll query(ll *BIT, ll index){
	ll sum=0;
	while(index>0){
		sum+=BIT[index];
		index -= (index & (-index));
	}
	return sum;
}
ll binarySearchLowerBound(ll *BIT,ll sum,ll n){
	ll l=1,r=n;
	ll pos;
	while(l<=r){
		ll mid=(l+r)>>1;
		ll cur = query(BIT,mid);
		if(cur == sum){
			pos = mid;
			r=mid-1;
		}
		if(cur < sum){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return pos;
}
void printCtrick(ll n){
	ll emptySpaces=n;
	ll *ans = new ll[n+1];
	ll start=1;
	ll *BIT = new ll[n+1];
	for(ll i=1;i<n+1;i++){
		BIT[i]=i- (i-( i & (-i))+1) +1;
	}
	for(ll shuffle=1;shuffle<=n;shuffle++){
		ll pos=shuffle%emptySpaces;
		ll emptySpacesTillStart =start;
		pos= emptySpacesTillStart+ pos;
		//if(pos % emptySpaces !=0){
			pos=pos % emptySpaces;
		//}
		ll index;
		if(pos==0){
			index = binarySearchLowerBound(BIT,emptySpaces,n); 
		}
		else{
		    index = binarySearchLowerBound(BIT,pos,n);	
		}
		ans[index]=shuffle;
		update(BIT,index,-1,n);
		emptySpaces--;
		if(pos==0){
			start=emptySpaces+1;
		}
		else{
			start=pos;
		}
				
	}
	for(ll i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,t;
	cin>>t;
	while(t--){
		cin>>n;
		printCtrick(n);
		cout<<"\n";
	}
	return 0;
}
