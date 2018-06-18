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
	mp.insert(make_pair('b',9));
	cout<<mp['b'];
	
	return 0;
}
