#include "bits/stdc++.h"
using namespace std;
 
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define watch(v) { for(int i = 0; i < v.size(); ++i){cout << v[i] << " "; }cout << endl; }
 
typedef long long ll;
// typedef int ll;
// #pragma warning("int")
 
typedef long double lld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
//mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
 
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 17928;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
 
 
 
void solve(int tc = 0) {
	cin >> n >> m;

	
  vi loc(n+m+1);
  vi dri(n+m+1);
	
	// put them on 1 -> n+m
  for (int i = 1; i <= n + m; ++i){
    cin >> loc[i];
  }
  
  for (int i = 1; i <= n + m; ++i){
    cin >> dri[i];
  }
  
	ll lc = 0;
	ll rc = n + m + 1;
	
	vi ld(n+m+1), rd(n+m+1);
  // left scan
  for (int i = 1; i <= n + m; ++i){
    if (dri[i])
			lc = i;
		ld[i] = lc;
  }
	//watch(ld);
	// right scan
	for (int i = n+m; i >=1; --i){
		if (dri[i])
			rc = i;
		rd[i] = rc;
	}
  //watch(rd)
	// closest drivers
	vi closer(n+m+1);
	
	for(int i = 1; i <= n+m; ++i){
		if (ld[i] == 0)
			closer[i] = rd[i];
		else if (rd[i] == n + m + 1)
			closer[i] = ld[i];
		else if ( loc[i] - loc[ ld[i] ] <= loc[ rd[i] ] - loc[i] )
			closer[i] = ld[i];
		else
			closer[i] = rd[i];
	}
	//watch(closer);
	vi counts(n+m+1);
	for (int i = 1; i <= n+m; ++i){
		if (!dri[i]){
			counts[ closer[i] ]++;
		}
	}
	//watch(counts);
	
	vi res;
	for (int i = 1; i <= n+m; ++i){
		if (dri[i]){
			res.push_back(counts[i]);
		}
	}
	
	// output
	for (int i = 0; i < res.size(); ++i){
		cout << res[i] << " " ;
	}
	cout << endl;
	
}
 
int main() {
	#ifdef leran_cai_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef leran_cai_local
		// usaco("evacuation");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
  solve();
		
	// int tc = 1;
	// cin >> tc;
	// for (int t = 0; t < tc; t++) {
	// 	solve(t);
	// }
	
	#ifdef leran_cai_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}