#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct minHeapNode{
	char c;
	ll fre;
	minHeapNode *left,*right;
	minHeapNode(char data,int frequency){
		left=right=NULL;
		c=data;
		fre=frequency;
	}
};
struct compare{
	bool operator()(minHeapNode *l,minHeapNode *r){
		return l->fre>r->fre;
	}
}; 
void printing(minHeapNode *curnode,string s){
	if(curnode->c!='$'){
		cout<<curnode->c<<"---> "<<s<<"\n";
		return;
	}
	printing(curnode->left,s+"0");
	printing(curnode->right,s+"1");
}
void print_codes(char *ch,ll *a,ll n){
	minHeapNode * top1,*top2,*topNew;
	priority_queue<minHeapNode *,vector<minHeapNode *>,compare> pq;
	for(ll i=0;i<n;i++){
		pq.push(new minHeapNode(ch[i],a[i]));
	}
	while(pq.size()>1){
		top1=pq.top();
		pq.pop();
		top2=pq.top();
		pq.pop();
		topNew= new minHeapNode('$',top1->fre+top2->fre);
		topNew->left=top1;
		topNew->right=top2;
		pq.push(topNew);
	}
	printing(pq.top(),"");
}
int main(){
	ll n;
	cin>>n;
	char *ch=new char[n];
	ll *a= new ll[n];
	for(int i=0;i<n;i++){
		cin>>ch[i];
		cin>>a[i];
	}
	print_codes(ch,a,n);
    
	return 0;
}

