// Source : https://www.hackerrank.com/challenges/preprocessor-solution/problem?isFullScreen=true

#include <limits>
#define FUNCTION(name, sign) void name(int& m, int v) { if(v sign m) m = v;}
#define toStr(a) #a
#define foreach(v, i) for(int i = 0; i < v.size(); i++)
#define io(v) cin>>v
#define INF (numeric_limits<int>::infinity())

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}