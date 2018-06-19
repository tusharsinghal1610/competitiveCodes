#include<iostream>
using namespace std;
bool check(long long int *height, long long int mid,long long int n,long long int m){
	long long int c=0,i=0;
	for(;i<n;i++){
		if(height[i]>mid)
		{
			c+=(height[i]-mid);
			if(c>=m){
				return true;
			}
		}
		
	}
	return false;
}
int main(){
	long long int ans,low,high,n,m,max,mid;
	cin>>n>>m;
	long long int *height = new long long int[n];
	max=0;
	for(int i=0;i<n;i++){
		cin>>height[i];	
		if(max<height[i]){
			max=height[i];
		}
	}
	low =0;
	high =max;
	ans=-1;
	while(low<=high){
		mid=(low+high)/2;
		if(check(height,mid,n,m)){
			ans=mid;
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
