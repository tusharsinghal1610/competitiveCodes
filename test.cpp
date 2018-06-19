#include<iostream>
using namespace std;
struct node{
	int ul;
	int ur;
};
int main(){
/*	int n=10;
	string s;
	int length;
	while(n--){
		cin>>length;
		cin>>string;
		int *tree = new int[4*length+1];
		build_tree();
	}*/
	node *st;
	st = new node[10];
	st[0].ul=5;
	st[0].ur=3;
	swap(st[0].ul,st[0].ur);
	cout<<st[0].ul;
	cout<<endl;
}
