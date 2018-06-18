#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int main(){
	priority_queue <int, vector <int>,greater <int>> pq;
	pq.push(45);
	pq.push(89);
	pq.push(1);
	cout<<pq.top();
	pq.pop();
	cout<<endl<<pq.top();
	pq.pop();
	cout<<endl<<pq.top();
	cout<<endl<<endl<<pq.empty();
	pq.pop();
	cout<<endl<<endl<<pq.empty();
	
	return 0;
	
}
