//finding the distance of every vertex from root 
// in O(m+n) time

#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;
vector<int> tree[SIZE];
int vis[SIZE],dist[SIZE];

void dfs(int v,int d){
    vis[v]=true;
    dist[v]=d;
    for(int to : tree[v]){
        if(vis[to]==false) dfs(to,d+1);
    }
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("cp.in", "r")) {
		freopen("cp.in", "r", stdin);
		freopen("cp.out", "w", stdout);
	}
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) vis[i]=0,dist[i]=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(0,0);
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
}

// //input
// 6 5
// 0 1
// 0 2
// 0 3
// 3 4
// 4 5

// //output
// 0 1 1 1 2 3 
