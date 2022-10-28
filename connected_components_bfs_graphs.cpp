#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;
vector<int> graph[SIZE];
bool vis[SIZE] = {false};
vector<vector<int>> comp;
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
            count++;
            vector<int> push;
            queue<int> q;
            q.push(i);
            push.push_back(i);
            vis[i] = true;
            while(q.empty() == false){
                int x = q.front();
                q.pop();
                for(int j : graph[x]){
                    if(vis[j]==false){
                        q.push(j);
                        push.push_back(j);
                        vis[j] = true;
                    }
                }
            }
            comp.push_back(push);
        }
    }
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        for(int j : comp[i]) cout<<j<<" ";
        cout<<endl;
    }

}




// //input:
// 11 10
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
