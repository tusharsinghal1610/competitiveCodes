#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector <int> a;
	a.resize(5);
	for(int i=0;i<5;i++){
		a[i]=i;
	}
	

	a.front()=5;
	a.insert(a.begin()+2,8);
	a.pop_back();
	a.push_back(9);
	cout<<a.size();
    for(int i=0;i<6;i++){
    	cout<<a[i]<<endl;
	}
	
	return 0;
}
