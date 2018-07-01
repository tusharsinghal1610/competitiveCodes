string max_parenthisized(string str){
    int length=str.length();
    stack <int> s;
    int start=0;finish=0;
    int final_start=0,final_finish=0;
    s.push(0);
    for(int i=1;i<length;i++){
    temp=s.top();
       if(str[i]=='('){
       s.push(i);
    }
    else if(str[i]==')'){
    	if(temp=='('){
    		s.pop();
		}
		else{
			s.clear();
			start=i+1;
			finish=i+1;
			continue;
		}
	}
	finish=i;
	if(finish -start > final_finish-final_start && s.empty()){
		final_finish=finish;
		final_start=start;
	}
	
}

	 string ans;
	 if(final_finish-final_start==0){
	 	return ans;
	 }
	 for(int i=final_start;i<=final_finish;i++){
	 	ans[i-final_start]=str[i];
	 }
	 return ans; 
}
