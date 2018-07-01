#include<iostream>
#include<map>
using namespace std;
int main(){
	map <char,int> mp;
	mp['b']=3;
	mp['c']=4;
	mp['d']=7;
	mp['d']=8;
	//cout<<mp.begin()->first;
	mp.erase('b');
	cout<<mp['b'];
	int *a = new int[5];
	cout<<a[0];
	return 0;
}
