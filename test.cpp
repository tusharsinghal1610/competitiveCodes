
#include<bits/stdc++.h>
using namespace std;
struct node{
	int ul;
	int ur;
};
bool comp(int i, int j){
	cout<<i<<" "<<j<<endl;

    if(i==j){
        return i>j;
    }
    if(i==0 || j==0){
        return i>j;
    }
    vector <int> digitsi;
    vector <int> digitsj;
    int temp;
    temp=i;
    while(temp!=0){
        digitsi.push_back(temp%10);
        temp/=10;
    }
    temp=j;
    while(temp!=0){
        digitsj.push_back(temp%10);
        temp/=10;
    }
    int leni=digitsi.size(),lenj=digitsj.size();
    if(leni>lenj){
        temp=leni-1;
        for(int k=lenj-1;k>=0;k--){
            if(digitsi[temp]>digitsj[k]){
                return digitsi[temp]>digitsj[k];
            }
            temp--;
        }
            return digitsi[temp]>digitsi[leni-1];
    }
    else{
        temp=lenj-1;
        for(int k=leni-1;k>=0;k--){
            if(digitsi[k]>digitsj[temp]){
                return digitsi[k]>digitsj[temp];
            }
            temp--;
        }
        return digitsj[temp]>digitsj[lenj-1];
    }
}
string largestNumber(vector<int> &A) {
    long long int len=A.size();
    vector<int> B(A);
  /*  for(int k=0;k<len;k++){
        B.push_back(A[k]);
    }*/
    sort(B.begin(),B.end(),comp);
    int digit;
    string s="",tempstr;
    long long int i,temp;
    cout<<"reached";
    for(i=len-1;i>=0;i--){
        temp=B[i];
        if(temp==0){
            s+=48;
            continue;
        }
        while(temp>0){
            tempstr="";
            digit=temp%10;
            tempstr+=(digit+48);
            s.insert(0,tempstr);
            temp/=10;
        }
    }
    if(s[0]=='0'){
        return "0";
    }
    return s;
}
int main(){
//int a[]={995,838};
int a[]={ 980, 674, 250, 359, 98, 969, 143, 379, 363, 106, 838, 923, 969, 880, 997, 664, 152, 329, 975, 377, 995, 943, 369, 515, 722, 302, 496, 124, 692, 993, 341, 785, 400, 113, 302, 563, 121, 230, 358, 911, 437, 438, 494, 599, 168, 866, 689, 444, 684, 365, 470, 176, 910, 204, 324, 657, 161, 884, 623, 814, 231, 694, 399, 126, 426};
vector<int> c;
cout<<"testing";
for(int i=0;i<65;i++){
	c.push_back(a[i]);
}
cout<<"--------------------------";
cout<<a[46]<<"------------------------------------------------";
cout<<largestNumber(c);
return 0;
}
