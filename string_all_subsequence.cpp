#include<iostream>
using namespace std;
void prnt_subsequence(string s, int a){ //o(n)
	int index=0;
	while(a){
		if(a &1){
			cout<<s[index];
		}
		index++;
		a=a>>1;
	}
}
void prnt_subsequence(string s, int l, int a){  // experimental o(n)
	int index=0;
	l=l-1;
	int temp=l;
	while(index <= l){
		if(a & (1<<temp)){
		cout<<s[index];
	    }
		index++;
		temp--;
	}
	
	
}
void prnt_subsequence_rev(string s, int l, int a){  // prints all subsequence in reverse order o(n)
	l=l-1;
	int k=0;
	while(a){
		if(a & 1){
			cout<<s[l-k];
		}
		a=a>>1;
		k++;
	}	
}
int main(){
	string s="abc";
	int length=s.length();
	int upper = 1<<(length);
	for(int i=0;i<upper;i++){                      //0(n * 2^n )
		prnt_subsequence(s,length,i);
		cout<<endl;
	}
	return 0;
}
