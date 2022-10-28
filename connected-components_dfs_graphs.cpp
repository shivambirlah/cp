#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;
vector<int> graph[SIZE];
bool vis[SIZE] = {false};
vector<vector<int>> comp;
void dfs(int vertex,vector<int> &x){
    vis[vertex] = true;
    x.push_back(vertex);
    for(int u:graph[vertex]){
        if(vis[u]==false) dfs(u,x);
    }
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("cp.in", "r")) {
		freopen("cp.in", "r", stdin);
		freopen("cp.out", "w", stdout);
	}
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    for(int i=0;i<n;i++){
        if(vis[i] == false){
            vector<int> x;
            dfs(i,x);
            count++;
            comp.push_back(x);
        }
    }
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        for(int j : comp[i]) cout<<j<<" ";
        cout<<endl;
    }

}




// //input:
// 10 10
// 0 2
// 0 4
// 0 5
// 1 4
// 1 5
// 2 3
// 2 4
// 4 5
// 9 10
// 7 8

// //output:
// 4
// 0 2 3 4 1 5 
// 6 
// 7 8 
// 9 10 
