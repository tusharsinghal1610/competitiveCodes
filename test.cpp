#include <iostream>
#include<vector>
#include<deque>
using namespace std;

int main() {
	// your code goes here
	long long int n;
	cin>>n;
	vector <long long int> a(n);
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}
	long long int k;
	cin>>k;
	deque <int> q;
	long long int i;
	for(i=0;i<k;i++){
		while(!q.empty() && a[i]>=a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
	}
	cout<<a[q.front()]<<" ";
	for(;i<n;i++){
		while(!q.empty() && a[i]>=a[q.back()]){
			q.pop_back();
		}
		q.push_back(i);
		while(q.front() <= i-k){
			q.pop_front();
		}
		cout<<a[q.front()]<<" ";
	}
	
	return 0;
}
