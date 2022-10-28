#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;
vector<int> graph[SIZE];
bool vis[SIZE] = {false};
int parent[SIZE];
int dist[SIZE];
int timer = 0;
int inTime[SIZE] = {0};
int outTime[SIZE] = {0};
void dfs(int vertex,int par){
    inTime[vertex] = timer++;
    if(par != -1) dist[vertex] = dist[par] + 1;
    parent[vertex] = par;
    vis[vertex] = true;
    for(int u:graph[vertex]){
        if(vis[u]==false){
            dfs(u,vertex);
        }
    }
    outTime[vertex] = timer++;
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
    dist[0]=0;
    dfs(0,-1);

    cout<<"Parent"<<endl;
    for(int i=0;i<n;i++) cout<<parent[i]<<" ";
    cout<<endl;

    cout<<"distance"<<endl;
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
    cout<<endl;

    cout<<"Intime"<<endl;
    for(int i=0;i<n;i++) cout<<inTime[i]<<" ";
    cout<<endl;

    cout<<"OutTime"<<endl;
    for(int i=0;i<n;i++) cout<<outTime[i]<<" ";
    cout<<endl;
}

// intput :
// 6 8
// 0 2
// 0 4
// 0 5
// 1 4
// 1 5
// 2 3
// 2 4
// 4 5



// output:
// Parent
// -1 4 0 2 2 1 
// distance
// 0 3 1 2 2 4 
// Intime
// 0 5 1 2 4 6 
// OutTime
// 11 8 10 3 9 7 

