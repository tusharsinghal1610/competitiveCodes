#include<iostream>
#include<list>
using namespace std;
int main(){
	list <int> li;
	cout<<li.empty();
	li.push_back(5);
	list <int>::iterator itr;
	itr = li.begin();
	cout<<*itr;
	cout<<li.empty();
	cout<<li.back();
	li.back()=8;
	cout<<li.back();
	list <int> li2;
	li2.push_back(3);
	li2.push_back(8);
	li2.push_back(6);
	li2.push_back(3);
	li2.push_back(9);
	list <int> ::iterator itr1;
	itr1 = li2.begin();
	
    
	cout<<endl;
/*	cout<<*itr1;
	itr1++;
	cout<<*itr1;
	itr1++;
	cout<<*itr1;
	itr1++;
	cout<<*itr1;
	li2.insert(li2.begin(),4);
	cout<<*li2.begin();*/
li2.reverse();
	for(int i:li2){
		cout<<i<<endl;
	}
	cout<<endl;
	cout<<li2.size()<<endl;
	li2.push_back(55);
	cout<<li2.size();
	return 0;
}
