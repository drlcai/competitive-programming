#include "bits/stdc++.h"
using namespace std;

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Macros ////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define printv(v) { printf("["); for(int i = 0; i < v.size(); ++i){cout << v[i] << ", "; } printf("]\n"); }
#define print2D(tb) { for (auto &row : tb){ printf("["); for (auto &column : row){ cout << column << ",\t"; } printf("]\n"); } }
#define printm(m) { for (auto const& [k, v]: m) {cout << "{" << k << ": " << v << "}\n"; } }
#define loop(b,e) for (ll idx = b; idx < e; idx++)
#define sz(a) (ll)a.size()

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<ll> vll;

///////////////////////////////////////////////////////////////////////
///////////////////////// Algorithms //////////////////////////////////
///////////////////////////////////////////////////////////////////////
const int pascal_size = 100;
ll Pascal[pascal_size + 1][pascal_size + 1] = {};

void create_pascal(){
	Pascal[0][0] = 1;
	for (int n = 1; n <= pascal_size; ++n) {
		Pascal[n][0] = Pascal[n][n] = 1;
		for (int k = 1; k < n; ++k)
			Pascal[n][k] = Pascal[n - 1][k - 1] + Pascal[n - 1][k];
	}

}

ull sum_to(ull n){
	return n * (n+1) / 2;
}


void initialize(){
	create_pascal();
}

///////////////////////////////////////////////////////////////////////
///////////////////////// Declarations ////////////////////////////////
///////////////////////////////////////////////////////////////////////
ll m, n, i, j, k;
string s;

///////////////////////////////////////////////////////////////////////

void solve(int tc = 0) {
	cin >> n;
	ull ans = n*4+1;
	
	ans += sum_to(n-2) + sum_to(n-1);
	
	cout << ans << endl;
}


int main()
{
    int tc = 1;
	cin >> tc;
	// initialize();
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
}