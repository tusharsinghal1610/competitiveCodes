#include<iostream>
using namespace std;
void build_tree(int *a,int *tree,int index,int s,int e){
	if(s>e)
	return;
	if(s==e){
		tree[index]=a[s];
		return;
	}
	int mid=(s+e)/2;
	build_tree(a,tree,2*index,s,mid);
	build_tree(a,tree,2*index+1,mid+1,e);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}
int query(int *tree,int index, int qs ,int qe, int s,int e ){
	if(qs >e || qe<s)
	return INT_MAX;
	if(qs <= s && qe >= e){
		return tree[index];
	}
	else{
		int mid=(s+e)/2;
		return min(query(tree,2*index,qs,qe,s,mid),query(tree,2*index+1,qs,qe,mid+1,e));
	}
}
void update_point(int *tree, int index,int i,int inc, int s, int e){
	if(i<s|| i>e){
		return;
	}
	if(i==s && i==e){
		tree[index]=tree[index]+inc;
	    return;
	}
	else{
		int mid =(s+e)/2;
		update_point(tree,2*index,i,inc,s,mid);
		update_point(tree,2*index+1,i,inc,mid+1,e);
		tree[index]=min(tree[2*index],tree[2*index+1]);
		return;
	}	
}
void range_update(int *tree,int index, int i,int j,int inc,int s,int e){
	if(j<s || i>e){
		return;
	}
	if(s==e){
		tree[index]+=inc;
		return;
	}
	else{
		int mid=(s+e)/2;
		range_update(tree,2*index,i,j,inc,s,mid);
		range_update(tree,2*index+1,i,j,inc,mid+1,e);
		tree[index]=min(tree[2*index],tree[2*index+1]);
		return;
	}
}
int main(){
	int a[]={1,3,2,7,5};
	int n=5;
	int *tree = new int[4*n+1];
	build_tree(a,tree,1,0,4);
/*	for(int j=0;j<10;j++){
		cout<<tree[j]<<endl;
	}*/
	//update_point(tree,1,0,10,0,4);
	//update_point(tree,1,1,10,0,4);
	range_update(tree,1,0,2,5,0,4);
	int n1;
	cin>>n1;
	while(n1--){
		int i,j;
		cin>>i>>j;
        cout<<query(tree,1,i,j,0,n-1)<<endl;		
	}
	return 0;
}
