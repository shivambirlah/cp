//O(n) space ;
//O(n^2) time

#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;
const int MAX = 1e6;

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("cp.in", "r")) {
		freopen("cp.in", "r", stdin);
		freopen("cp.out", "w", stdout);
	}
    vector<int> wt = {1,3,5};
    int sum = 11;
    vector<int> dp(sum+1,MAX);
    dp[0] = 0;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<wt.size();j++){
            if(i-wt[j]>=0) dp[i] = min(dp[i],1+dp[i-wt[j]]);
        }
    }
    //for(int i=0;i<=sum;i++) cout<<dp[i]<<" ";
    cout<<dp[sum]<<endl;
}

//output
3
