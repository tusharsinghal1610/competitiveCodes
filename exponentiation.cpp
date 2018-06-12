#include<iostream>
using namespace std;
int rec_exp(int n,int b){ // o(n)
	if(b==0)
	return 1;
	if(b==1){
	return n;
   }
   return rec_exp(n,b-1) * n;
}
int fast_exp(int n, int b){   //o(logn)
	if(b==0)
	return 1;
	if(b==1)
	return n;
	int num;
	if(b%2==0){
		num = fast_exp(n,b/2);
		return num*num;
	}
	return n * fast_exp(n,b-1);
}
int iterative_fast_exp(int n,int b){ //o(logn)
	int ans=1;
	while(b){
		if(b & 1){
			ans *= n;
		}
		b= b>>1;
		n*=n;
	}
	return ans;
}
int main(){
	cout<<rec_exp(2,10)<<endl;
	cout<<fast_exp(2,10)<<endl;
	cout<<iterative_fast_exp(2,10);
	return 0;
}
