#include<iostream>
using namespace std;
struct node{
	int ul;
	int ur;
};
void build_tree(string str,node *tree,int index,int s,int e){
	if(s>e)
	return;
	if(s==e){
		if(str[s]=='('){
			tree[index].ul=1;
			tree[index].ur=0;
		}
		else{
			tree[index].ur=1;
			tree[index].ul=0;
		}
		return;
	}
	int mid=(s+e)/2;
	build_tree(str,tree,2*index,s,mid);
	build_tree(str,tree,2*index+1,mid+1,e);
	tree[index].ul=tree[2*index+1].ul + max(0,tree[2*index].ul-tree[2*index+1].ur);
	tree[index].ur=tree[2*index].ur+max(0,tree[2*index+1].ur - tree[2*index].ul);
	return;
}
void update(node *tree, int index, int s, int e, int i){
	if(i<s || i>e){
		return;
	}
	if(s==e){
		swap(tree[index].ul,tree[index].ur);
	}
	else{
		int mid=(s+e)/2;
		update(tree,2*index,s,mid,i);
		update(tree,2*index+1,mid+1,e,i);
		tree[index].ul=tree[2*index+1].ul + max(0,tree[2*index].ul-tree[2*index+1].ur);
		tree[index].ur=tree[2*index].ur+max(0,tree[2*index+1].ur - tree[2*index].ul);
		return;
	}
}
int main(){
	int n=1;
	string str;
	int length;
	while(n<=10){
		cin>>length;
		cin>>str;
		node *tree = new node[4*length+1];
		build_tree(str,tree,1,0,length-1);
	    int m;
	    cin>>m;
	    cout<<"Test "<<n<<":"<<endl;
	    n++;
	    int k;
	    for(int i=0;i<m;i++){
	    	cin>>k;
	    	if(k==0){
	    		if(tree[1].ul==0 && tree[1].ur==0){
	    			cout<<"YES"<<endl;
				}
				else{
					cout<<"NO"<<endl;
				}
			}
			else{
				update(tree,1,0,length-1,k-1);
			}
		}		
	}
	return 0;
}
