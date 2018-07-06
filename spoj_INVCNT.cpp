#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> BIT(10000007,0);
ll inv_count =0;
ll n;

void update(ll index,ll val){
	while(index<=10000006){
		BIT[index]+=val;
		index += (index & (-index));
	}
}
ll query(int index){
	ll sum=0;
	while(index>0){
		sum+=BIT[index];
		index -= (index & (-index));
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
	
		char ch;
		cin>>n;
		int *a=new int[n+1];
		for(ll i=1;i<n+1;i++){
			cin>>a[i];
		}
		//cin>>ch;
		for(ll i=n;i>=1;i--){
			inv_count+=query(a[i]-1);
			update(a[i],1);	
		}
		cout<<inv_count<<"\n";
		inv_count=0;
		for(ll i=0;i<10000005;i++)
		BIT[i]=0;
		
	}
	return 0;
}
