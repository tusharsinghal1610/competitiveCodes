#include<iostream>
using namespace std;
int twonplus1(int *a,int size){ // 2n+1 o(n)
	int temp=0;
	for(int i=0;i<size;i++){
		temp = temp ^ a[i];
	}
	return temp;
}
void twonplus2(int *a, int size){ //2n+2 o(n)
	int temp=0;
	for(int i=0;i<size;i++){
		temp = temp ^ a[i];
	}
	int pos=0;
	int tmp_copy=temp;
	while (!(temp&1)){
		pos++;
		temp = temp >> 1;
	}
	int firstans=0;
	for(int i=0;i<size;i++){
		if(a[i] & (1<<pos)){
			firstans=firstans ^ a[i];
		}
	}
	int secondans= tmp_copy^firstans;
	cout<<"numbers are"<<firstans<<" "<<secondans;
}
int threenplus1(int *a, int size){ //3n+1 o(n)
	int frcount[10];
	for(int i=0;i<10;i++){
		frcount[i]=0;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<size;j++){
			if(a[j] & (1<<i)){
				frcount[i]++;
			}
		}
	}
	long long int ans=0;
	for(int i=9;i>=0;i--){
		frcount[i]=frcount[i]%3;
		ans=ans*2 + frcount[i];
	}
	return ans;
}
int main(){
	int a[]={2,2,2,4,8,4,3,3,3,4,5,5,5};
	cout<<threenplus1(a,10);
	return 0;
}
