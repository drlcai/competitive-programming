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
#define watcharr(arr, n) {for(int i = 0; i < n; ++i){cout << arr[i] << " ";} cout << endl; }
#define watchmap(table) {for(auto const& [key, value] : table){cout << key << " " << value << endl;} } 

typedef long long ll;
// typedef int ll;
// #pragma warning("int")

typedef long double lld;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef deque<int> di;

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



void solve(int tc = 0) {
	cin >> n >> m;
	
	map<int, di> color2idx;
	
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i){
		cin >> b[i];
		if (a[i] != b[i]){			
			// make color to indices
			if (color2idx.find(b[i]) != color2idx.end()){
				color2idx[ b[i] ].push_back(i);
			}else{
				di temp;
				temp.push_back(i);
				color2idx.insert(make_pair(b[i], temp) );
			}
		}
	}
	for (int i = 0; i < m; ++i){
		cin >> c[i];
	}
	
	// for (auto it = color2idx.begin(); it != color2idx.end(); it++){
	// 	di temp = it->second;
	// 	for(int i = 0; i < temp.size(); i++){
	// 		cout << temp[i] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	int last = -1;
	if (color2idx.find(c[m-1]) == color2idx.end()){ // no such color
		for (int i = 0; i < n; ++i){
			if (b[i] == c[m-1]){
				last = i;
				break;
			}
		}
		if (last == -1){
			cout << "NO" << endl;
			return;
		}

	}
	
	vi ans(m);
	
	// treat c[m-1], it can be in color2idx or not. 
	auto it = color2idx.find(c[m-1]);
	if (it != color2idx.end()){
		ans[m-1] = it->second[0] + 1;
		it->second.pop_front();
		
		if (it->second.empty()){
			color2idx.erase(c[m-1]);
		}
	}else{
		ans[m-1] = last + 1;
	}
	
	
	
	// for all colors in c, greedily paint them and change table and remove it from table.
	for (int i = 0; i < m-1; ++i){
		auto it = color2idx.find(c[i]);
		if ( it == color2idx.end() ){
			ans[i] = ans[m-1];
		}else{
			ans[i] = it->second[0] + 1;
			it->second.pop_front();
			if( it->second.empty() ){
				color2idx.erase(c[i]);
			}
		}
		
	}
	
	
	
	if (color2idx.size() > 0){
		cout << "NO" << endl;
		//watch(ans);
	}else{
		cout << "YES" << endl;
		watch(ans);
	}
	
	

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
