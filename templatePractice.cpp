#include<iostream>
using namespace std;
template <class T,class compare>
int search(T a[],int n, T e,compare obj){
	for(int i=0;i<n;i++){
		if(obj(a[i],e)){
			return i;
		}
	}
	return -1;
}
class compareint{
	public:
		bool operator()(int i, int j){
			return i==j;
		}
};
int main(){
	compareint obj;
//	char ch[]="abcdefghijklmnopqrstuvwxyz";
	int a[]={2,3,4,5,6,7,8,9,2,3,4,45,5,6,55,77,7,6,6};
//	cout<<search(ch,26,'e')<<endl;
	cout<<search(a,19,45,obj);
	return 0;
}
