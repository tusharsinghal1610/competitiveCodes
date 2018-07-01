#include<iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct node {
	long long int suffix,prefix,total,best;
};
void build_tree(int *a, node *tree,long long int index,long long int s,long long int e){
	if(s>e)
	return;
	if(s==e){
		tree[index].suffix=a[s];
		tree[index].prefix=a[s];
		tree[index].total=a[s];
		tree[index].best=a[s];
		return;
	}
	long long int mid=(s+e)>>1;
	build_tree(a,tree,2*index,s,mid);
	build_tree(a,tree,2*index+1,mid+1,e);
	tree[index].suffix=max(tree[2*index+1].suffix,tree[2*index+1].total+tree[2*index].suffix);
	tree[index].prefix=max(tree[2*index].prefix,tree[2*index].total+tree[2*index+1].prefix);
	tree[index].total=tree[2*index].total + tree[2*index+1].total;
	tree[index].best=max(tree[2*index].suffix+tree[2*index+1].prefix,max(tree[2*index].best,tree[2*index+1].best));
	return;
}
node query(node *tree,long long int index, long long int s,long long int e,long long int x,long long int y){
	if(x>e || y<s ||s>e){
		node temp;
		temp.best=temp.prefix=temp.suffix=INT_MIN;
		temp.total=0;
		return temp;
	}
	if(x<=s && y>=e){
		return tree[index];
	}
	long long int mid=(s+e)>>1;
	node temp1=query(tree,2*index,s,mid,x,y);
	node temp2=query(tree,2*index+1,mid+1,e,x,y);
	node temp3;
	temp3.prefix=max(temp1.prefix,temp1.total+temp2.prefix);
	temp3.suffix=max(temp2.suffix,temp1.suffix+temp2.total);
	temp3.total=temp1.total+temp2.total;
	temp3.best=max(temp1.suffix+temp2.prefix,max(temp1.best,temp2.best));
	return temp3;
}
int main(){
	long long int m,x,y;
	int n;
	int a[50003];
    scanf("%d",&n);
    	//long long int *a=new long long int[n];
//	cin>>n;
	for(long long int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    node *tree = new node[4*n+1];
	build_tree(a,tree,1,0,n-1);
	scanf("%d",&m);
	for(long long int i=0;i<m;i++){
		scanf("%d",&x);
		scanf("%d",&y);
		node temp = query(tree,1,0,n-1,x-1,y-1);
		printf("%d\n",temp.best);
	}
	return 0;
}
