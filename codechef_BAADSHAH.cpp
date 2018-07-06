#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll *BIT = new ll[100009];
ll n;
void update(ll index, ll val){
	while(index <= n){
		BIT[index]+=val;
		index += (index & (-index));
	}
}
ll query(ll index){
	ll sum=0;
	while(index>0){
		sum+=BIT[index];
		index -= (index & (-index));
	}
	return sum;
}
void build_BIT(ll *a){
	for(ll i=1;i<=n;i++){
		update(i,a[i]);
	}
}
ll binarySearch(ll sumR){
	ll l=1,r=n;
	
	while(l<=r){
		ll mid=(l+r)>>1;
		ll ans= query(mid);
		if(ans == sumR){
			return mid;
		}
		if(ans>sumR){
			r=mid-1;
		}
		else{
	        l=mid+1;	
		}
	}
	return 0;
}
int main(){

	for(ll i=0;i<100007;i++){
		BIT[i]=0;
	}
	ll m;
	ll x,y,z,value;
	cin>>n>>m;
	ll *a=new ll[n+1];
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	build_BIT(a);
	for(ll k=0;k<m;k++){
		cin>>x;
		if(x==1){
			cin>>y>>z;
		    value=z-a[y];
			a[y]=z;
			update(y,value);
		}
		else{
			cin>>y;
			ll index = binarySearch(y);
			if(index!=0){
				cout<<"Found "<<index;
			}
			else{
				cout<<"Not Found";
			}
			if(k!=m-1)
			cout<<"\n";
		}
	}
	
	return 0;
}
