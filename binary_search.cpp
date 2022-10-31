#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("cp.in", "r")) {
		freopen("cp.in", "r", stdin);
		freopen("cp.out", "w", stdout);
	}
    //implementation 
    int n ;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k ;
    cin>>k;
    int l= -1,r=n;
    while(r-l > 1){
        int m = (r+l)/2;
        if(k < v[m]) r =  m;
        else l = m;
    }
    cout<<l<<" "<<r<<endl;

    //arbitary predicate //seperation of 0 and 1
    
    cin>>n;
    vector<int> f(n);
    for(int i=0;i<n;i++) cin>>f[i];
    l = -1, r = n;
    while(r-l> 1){
        int m = (l+r)/2;
        if(f[m]) r = m;
        else l = m;
    }
    cout<<l<<" "<<r<<endl;

}

//input 

5
1 3 3 4 4
2

7
0 0 0 1 1 1 1 

//output 
  
0 1
2 3

