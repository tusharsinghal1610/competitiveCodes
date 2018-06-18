#include<iostream>
#include<set>
using namespace std;
int main(){
	set <int> s1;
	int a[] = {5,5,4,3,2,1,6};
	set <int> s2(a,a+6);
//	s2.clear();
cout<<s2.count(5)<<endl;
cout<<s2.count(8)<<endl;
s2.erase(5);
	for(auto i:s2){
		cout<<i<<endl;
	}
	cout<<endl<<endl;
	multiset <int> m1(a,a+7);
	for(auto i:m1){
		cout<<i<<endl;
	}
	
cout<<m1.count(5)<<endl;
cout<<m1.count(8)<<endl;
if(s2.end()==s2.find(8)){
	cout<<"tushar";
}
else{
	cout<<"singhal";
}
}
