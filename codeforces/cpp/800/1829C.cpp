#include "bits/stdc++.h"
using namespace std;

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Macros ////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define printv(v) { printf("["); for(int i = 0; i < v.size(); ++i){cout << v[i] << ", "; } printf("]\n"); }
#define printm(m) { for (auto const& [k, v]: m) {cout << "{" << k << ": " << v << "}\n"; } }
#define loop(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<ll> vll;

///////////////////////////////////////////////////////////////////////
///////////////////////// Algorithms //////////////////////////////////
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
///////////////////////// Declarations ////////////////////////////////
///////////////////////////////////////////////////////////////////////
ll m, n, i, j, k;
string s;

///////////////////////////////////////////////////////////////////////

void solve(int tc = 0) {
	cin >> n;
	vll v0, v1, v2;
	ll bothmin = 2e5+1;

	loop(i,n){
		cin >> m >> s;	
		if (s.compare("11") == 0){
			v0.push_back(m);
		}else if (s.compare("10") == 0){
			v1.push_back(m);
		}else if (s.compare("01") == 0){
			v2.push_back(m);
		}
		
	}
	sort(v0.begin(), v0.end());	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	// printv(v0);
	// printv(v1);
	// printv(v2);

	if (v0.size() == 0){
		if (v1.size() == 0 || v2.size()==0){
			cout << -1 << endl;
		}else{
			cout << v1[0]+v2[0] << endl;
		}
	}else{
		if (v1.size()==0 || v2.size()==0){
			cout << v0[0] << endl;
		}else{
			cout << min(v1[0]+v2[0], v0[0]) << endl;
		}
	}
	
}


int main()
{
    int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
}