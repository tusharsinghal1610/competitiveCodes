#include<iostream>
using namespace std;
int main(){
	string s1="tushar";
	string s2(s1);
	s2="tanya";
	s2+=" singhal";
	string s3(s2,0,4);
	string s4(s3.begin(),s3.end());
	s4.append(" ji");
	string::iterator itr = s4.begin();
	itr+=3;
	s4.clear();
	string s5("tanya");
	string s6(s5);
	string s7 = "tusha";
	char buffer[20];
	cout<<s5<<endl;
	cout<<s6<<endl;
	cout<<s7<<endl;
	cout<<s5.compare(s7)<<endl;
    int t= s7.copy(buffer,4,0);
    buffer[t]='\0';
    cout<<buffer;
    cout<<s7.empty();
    s7.clear();
    cout<<s7.empty()<<endl;
    string::iterator itr1=s6.end();
    --itr1;
    cout<<*itr1;
    string s9("helloWorld");
    string s8("helloWorld");
    s8.erase(s8.begin()+3,s8.end()-3);
    cout<<endl<<s8;
    cout<<s9.find('l');
    cout<<s9.find("ld");
    s9.insert(s9.begin()+3,'h');
    cout<<endl<<s9;
    string s10;
    s10= s9.substr(0,5);
    cout<<endl<<s10;
	return 0;
}

