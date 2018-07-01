#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
	return a.second.second<b.second.second;
}
void update(int *tree,long int index,long int s, long int e, long int i,long int val){
	if(s>e  || i<s || i>e){
		return;
	}
	if(s==e){
		tree[index]=val;
		return;
	}
	long int mid=(s+e)>>1;
	update(tree,index<<1,s,mid,i,val);
    update(tree,(index<<1)+1,mid+1,e,i,val);	
    tree[index]=tree[2*index]+tree[2*index+1];
}
long int query(int *tree,long int index, long int s, long int e, long int qs,long int qe){
	if(qs>e || qe< s){
		return 0;
	}
	if(qs<=s && qe>=e){
		return tree[index];
	}
	long int mid=(s+e)>>1;
	long int val1 = query(tree,index<<1,s,mid,qs,qe); 
	long int val2 = query(tree,(index<<1)+1,mid+1,e,qs,qe);
	return val1+val2;
}
int main(){
	long int n,i,q,value,temp;
	map <long int,long int> mp;
	scanf("%lld",&n);
	long int * a= new long int[n+1];
	for(i=1;i<n+1;i++){
		scanf("%lld",&a[i]);
	}
	cin>>q;
	vector <pair<long long int,pair<long long int,long long int>>> queries(q+1);
	
	for(i=1;i<q+1;i++){
		queries[i].first=i;
		scanf("%lld",&queries[i].second.first);
		scanf("%lld",&queries[i].second.second);
	}
	sort(queries.begin()+1,queries.end(),comp);
	long int *ans= new long int[q+1];
    int *tree = new int[4*n+10];
	for(i=0;i<4*n+10;i++){
		tree[i]=0;
	}
	long int realized=0;
	for(i=1;i<q+1;i++){
		
		while(queries[i].second.second>realized){
			realized++;
			if(mp[a[realized]]==0){
				mp[a[realized]]=realized;
				update(tree,1,1,n,realized,1);
			}
			else{
				temp=mp[a[realized]];
				mp[a[realized]]=realized;
				update(tree,1,1,n,temp,0);
				update(tree,1,1,n,realized,1);
			}
		}
	
	value=query(tree,1,1,n,queries[i].second.first,queries[i].second.second);
	ans[queries[i].first]=value;
	}
	for(i=1;i<q+1;i++){
	//	cout<<ans[i]<<endl;
		printf("%lld",ans[i]);
		if(i!=q){
			printf("\n");
		}
	}
	return 0;
}
