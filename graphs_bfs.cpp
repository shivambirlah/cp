#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int N = 1e5+6;
vector<int> graph[N];
bool visited[N]={false};
int parent[N] ;
int dist[N] ;

void path(int to){
    vector<int> ret;
    for(;parent[to]!=-1;to=parent[to]){
        ret.push_back(to);
    }
    for(int i=0;i<ret.size();i++) cout<<ret[i]<<" ";
    cout<<0<<endl;
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
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    parent[0] = -1;
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int u : graph[x]){
            if(visited[u]==false){
                q.push(u);
                visited[u] = true;
                dist[u] = 1 + dist[x];
                parent[u] = x;
            }
        }
    }
    path(3);
    cout<<dist[1]<<endl;
    cout<<dist[5]<<endl;
}


// input
// 6 8
// 0 2
// 0 4
// 0 5
// 1 4
// 1 5
// 2 3
// 2 4
// 4 5



// output
// 3 2 0
// 2
// 1
