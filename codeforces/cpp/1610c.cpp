#include "bits/stdc++.h"
using namespace std;
 
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
 
typedef long long ll;
// typedef int ll;
// #pragma warning("int")
 
typedef long double lld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;

typedef pair<int, int> pii;
 
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
 
bool possible(vector<pii> people, int mid){
	// int used = 0;
	// int target = mid;
	
	// for (int i = 0; i < people.size(); ++i){
	// 	// when can we choose the current one?
	// 	// if the chosen ppl are <= before (it's allowed)
	// 	// the target <= 1 + after
	// 	if (used > people[i].second) continue;
	// 	if (target > 1 + people[i].first) continue;
	// 	used ++;
	// 	target --;
	// }
	
	// return target <= 0;
	ll c = 0;
	for(ll i = 0; i < n; i++){
		if(mid - 1 - people[i].first <= c && c <= people[i].second) c++;
	}
	return c >= mid;
}
 
void solve(int tc = 0) {
	cin >> n;
	
	// <after, before>
	vector<pii> people(n);
	
	for (int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		people[i] = make_pair(a,b);
	}
	
	// [lo, hi)
	int lo = 0; 
	int hi = n;
	
	// end condition [lo == hi)
	while (lo < hi){
		int mid = lo + (hi - lo + 1) / 2;
		
		if (possible(people, mid)){
			lo = mid;
		}else{
			hi = mid - 1;
		}
	}
	
	cout << lo << endl;
	
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
 
	
		
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef leran_cai_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}