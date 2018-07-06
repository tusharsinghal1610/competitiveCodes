#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map <int , list<pair<int,int>>> graph;
void addEdge(int a,int b,int w){
	graph[a].push_back(make_pair(b,w));
	graph[b].push_back(make_pair(a,w));
}
void dfs(int i,int j){
	for(auto neighbour:graph[i]){
		if((neighbour.first) != j){
			dfs(neighbour.first,i);
		}
	}
	cout<<i;
}
int measureHeight(int i, int j){
	if(graph[i].size()==1){
		return 0;
	}
	else{
		int maximum=0;
		for(auto neighbour:graph[i]){
		if(neighbour.first != j){
			maximum=max(maximum,measureHeight(neighbour.first,i));
		}
	}
		return maximum+1;
	}
	
}
pair<int,int> lowestNode(int i,int j){
		if(graph[i].size()==1 && graph[i].front().first==j){
		return make_pair(i,0);
	}
	else{
		int maximum=-1;
		int element;
		for(auto neighbour:graph[i]){
		if(neighbour.first != j){
			pair <int,int> p;
			p=lowestNode(neighbour.first,i);
			if(p.second>maximum){
				maximum=p.second;
				element=p.first;
			}
		}
	}
		return make_pair(element,maximum+1);
	}
}
int diameter_through_double_dfs(){
	pair <int,int> temp = lowestNode(1,1);
	temp = lowestNode(temp.first,temp.first);
	return temp.second;
}
pair<int,int> diameter_through_dp(int i, int j){
	if(graph[i].size()==1 && graph[i].front().first==j){
		return make_pair(0,0);
	}
	else{
		int maxheight1=0,maxheight2=0,maxdiameter=0;
		for(auto child:graph[i]){
			if(child.first!=j){
				pair<int,int> temp=diameter_through_dp(child.first,i);
				if(maxdiameter<temp.first){
					maxdiameter=temp.first;
				}
				if(temp.second>maxheight1){
					maxheight2=maxheight1;
					maxheight1=temp.second;
				}
				else if(temp.second>maxheight2){
					maxheight2=temp.second;
				}
			}
		}
		maxdiameter= max(maxdiameter,maxheight1+maxheight2+2);
		return make_pair(maxdiameter,maxheight1+1);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,a,b,w;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>w;
		addEdge(a,b,w);
	}
	//dfs(1,1);
	//cout<<measureHeight(1,1);
	//pair <int,int> temp=lowestNode(1,1);
	//cout<<temp.first<<temp.second;
	//cout<<diameter_through_double_dfs();
	/*----------- input test----------
	9
1 2 3
2 3 4
3 4 2
2 5 4
1 6 4
6 7 4
7 9 4
6 8 2
4 10 4 
*/
	pair <int,int> temp =diameter_through_dp(1,1);
	cout<<temp.first;
	return 0;
}
