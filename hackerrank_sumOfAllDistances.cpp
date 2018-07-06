#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map <ll,list<pair<ll,ll>>> graph;
unordered_map <ll,ll> nodes;
unordered_map <ll,ll> distances;
unordered_map <ll,ll> answer;
ll n;
void addEdge(ll a,ll b,ll w){
	graph[a].push_back(make_pair(b,w));
	graph[b].push_back(make_pair(a,w));
}
ll calNumOfNodes(ll a, ll b){
	if(graph[a].size() == 1 && graph[a].front().first==b){
		return nodes[a]=1;
	}
	else{
		ll total=0;
		for(auto neighbour:graph[a]){
			if(neighbour.first!=b)
			total+=calNumOfNodes(neighbour.first,a);
		}
		return nodes[a]=total+1;
	}
}
ll calDistances(ll a,ll b){
	if(graph[a].size() == 1 && graph[a].front().first==b){
		return distances[a]=0;
	}
	else{
		ll total=0;
		for(auto neighbour:graph[a]){
			if(neighbour.first!=b){
				total+=(calDistances(neighbour.first,a) + neighbour.second * nodes[neighbour.first]);
			}
		}
		return distances[a]=total;
	}
}
void calSumDistances(ll a,ll b){
	if(graph[a].size() == 1 && graph[a].front().first==b){
		return;
	}
	else{
		for(auto neighbour:graph[a]){
			if(neighbour.first != b){
				answer[neighbour.first]=answer[a] + neighbour.second *( n - 2*nodes[neighbour.first]);
				calSumDistances(neighbour.first,a);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		ll temp=n-1;
		ll x,y,z;
		while(temp--){
			cin>>x>>y>>z;
			addEdge(x,y,z);
		}
		calNumOfNodes(1,1);
	    calDistances(1,1);
	    answer[1]=distances[1];
	    calSumDistances(1,1);
	    for(ll i=1;i<=n;i++){
	    	cout<<answer[i]<<endl;
		}
		graph.clear();
	}
}
