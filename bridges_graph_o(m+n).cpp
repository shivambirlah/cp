#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;
vector<int> g[SIZE];
int low[SIZE],tin[SIZE],vis[SIZE];
int timer = 0;

void dfs(int v,int p = -1){
    vis[v] = 1;
    low[v] = tin[v] = timer++;
    for(int to : g[v]){
        if(to != p){
            if(vis[to]) low[v] = min(low[v],low[to]);
            else{
                dfs(to,v);
                low[v] = min(low[v],low[to]);
                if(low[to] > tin[v]) cout<<v<<" "<<to<<endl;
            }
        }
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
    for(int i=0;i<n;i++) low[i]=tin[i]=-1,vis[i]=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
    
}





// ///input
// 8 8
// 5 1
// 0 4
// 1 4
// 2 3
// 4 5
// 4 7
// 3 7
// 7 6 
  
  
  
//  // output
//   3 2
// 7 3
// 7 6
// 4 7
// 0 4
