#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define MOD 1000000007
ll k;
vector<ll> a,b,c,d;
vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>>B){
	vector <vector<ll>> C(k+1,vector<ll>(k+1));
	for(ll i=1;i<k+1;i++){
		for(ll j=1;j<k+1;j++){
			for(ll p=1;p<k+1;p++){
				C[i][j]=(C[i][j]+(A[i][p]*B[p][j])%MOD)%MOD;
			}
		}
	}
	return C;
}
vector<vector<ll>> pow(vector<vector<ll>> A,ll p){
	if(p==1){
		return A;
	}
	else if(p&1){
		return multiply(A,pow(A,p-1));
	}
	else{
		vector<vector<ll>> temp=pow(A,p/2);
		return multiply(temp,temp);
	}
}
ll compute(ll n){
	if(n<=0){
		return 0;
	}
	vector <ll> F1(k+1);
	for(ll i=0;i<k;i++){
		F1[i+1]=b[i];
	}
	vector<vector<ll>> T(k+1,vector <ll> (k+1));
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=k;j++){
			if(i<k-1){
				if(j==i+1){
					T[i][j]=1;
				}
				else{
					T[i][j]=0;
				}
				continue;
			}
			else if(i==k-1)
			T[i][j]=c[k-j];
			else
			T[i][j]=d[k-j];
		}
	}
	
	T = pow(T,n);
	ll res=0;
	for(ll i=1;i<=k;i++){
		res=(res + (T[k][i]*F1[i])%MOD)%MOD;
	}
	return res;
	
}
int main(){
	b.push_back(0);
	b.push_back(1);
	b.push_back(0);
	c.push_back(0);
	c.push_back(1);
	c.push_back(1);
	d.push_back(1);
	d.push_back(1);
	d.push_back(0);
	k=3;
	ll test;
	ll N,M;
	cin>>test;
	while(test--){
		cin>>N>>M;
		ll temp1=compute(M);
		ll temp2=compute(N-1);
		
		ll ans= (temp1-temp2)%MOD;
		if(ans<0){
			ans+=MOD;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
