#include<iostream>
using namespace std;
//the counting of bits start from 0 and from right to left
int rightShift(int a,int i){   //O(1)
	return a>>i;
}
int leftShift(int a,int i){   //O(1)
	return a<<i;
}
bool check_i_bit(int a, int i){   //O(1)
	return 0 < (a & (1<<i));
}
int countingSetBits(int a){     //O(logn)
	int count =0;
	while(a){
		count += (a & 1);
		a = a>>1;
	}
	return count;
}
int countingSetBitsFast(int a){    //<=O(logn)
	int count =0;
	while(a){
		count++;
		a= a & (a-1);
	}
	return count;
}
int main(){
	int a=99;
	cout<<"ls by 2  "<<leftShift(a,2)<<endl;
	cout<<"rs by 2  "<<rightShift(a,2)<<endl;
	cout<<"check 3th bit"  <<check_i_bit(a,3)<<endl; 
	cout<<"check 2th bit   "<<check_i_bit(a,2)<<endl;
	cout<<"counting set bits  "<<countingSetBits(a)<<endl;
    cout<<"counting set bits fast  "<<countingSetBitsFast(a)<<endl;
	return 0;
}
