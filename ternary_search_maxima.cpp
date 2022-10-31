//logn time
#include<bits/stdc++.h>
#define int int64_t
using namespace std;
const int SIZE = 1e6 + 5;

double f(double x){
    return -x*x + 8*x - 15;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("cp.in", "r")) {
		freopen("cp.in", "r", stdin);
		freopen("cp.out", "w", stdout);
	}
    //ternary search 
    //finding maxima 
    double l = 0 , r = 6;
    double eps = 1e-9;
    while(r-l > eps){
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;
        double f1 = f(m1);
        double f2  = f(m2);
        if(f1 < f2) l = m1;
        else r = m2;
    }
    cout<<"{"<<l<<","<<f(l)<<"}"<<endl;
}


//output

{4,1}
