#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	unordered_map <string, int> mp;
	mp["mango"]=28;
	cout<<mp["mango"];
	mp["banana"]=98;
	cout<<mp["banana"];
	unordered_map <int,int> m;
	m[5]=6;
	m[6]=7;
	m[8]=3;
	m[1]=3;
	cout<<endl;
	cout<<m[5]<<endl;
    cout<<m[6]<<endl;
	cout<<m[8]<<endl;
	cout<<m[7]<<endl;	
	m.insert(make_pair(10,11));
	cout<<m[10];
	m.erase(10);
	cout<<endl<<m[10];
	cout<<m.load_factor();
	return 0;
}
