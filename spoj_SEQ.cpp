#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define MOD 1000000000
ll k;
vector<ll> a,b,c;
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
	if(n<=k){
		return b[n-1];
	}
	vector <ll> F1(k+1);
	for(ll i=0;i<k;i++){
		F1[i+1]=b[i];
	}
	vector<vector<ll>> T(k+1,vector <ll> (k+1));
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=k;j++){
			if(i<k){
				if(j==i+1){
					T[i][j]=1;
				}
				else{
					T[i][j]=0;
				}
				continue;
			}
			T[i][j]=c[k-j];
		}
	}
	
	T = pow(T,n-1);
	ll res=0;
	for(ll i=1;i<=k;i++){
		res=(res + (T[1][i]*F1[i])%MOD)%MOD;
	}
	return res;
	
}
int main(){
	ll test,temp,n;
	cin>>test;
	while(test--){
		cin>>k;
		for(ll p=0;p<k;p++){
			cin>>temp;
			b.push_back(temp);
		}
		for(ll p=0;p<k;p++){
			cin>>temp;
			c.push_back(temp);
		}
		cin>>n;
		cout<<compute(n)<<endl;
		b.clear();
		c.clear();
	}
	return 0;
}
