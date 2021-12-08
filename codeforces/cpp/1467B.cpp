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

int ishill(int i){
  if (i > 0 && i < n - 1 && a[i] > a[i-1] && a[i] > a[i+1])
    return true;
  return false;
}

int isvalley(int i){
  if (i > 0 && i < n - 1 && a[i] < a[i-1] && a[i] < a[i+1])
    return true;
  return false;
}

void solve(int tc = 0) {
  cin >> n;
  memset(a, 0, 3*1e5);
  memset(b, 0, 3*1e5);
  
  for (int i = 0; i < n; ++i){
    cin >> a[i];
  }
  
  
  ll sum = 0;
  for (int i = 1; i < n-1; ++i){
    if (ishill(i) or isvalley(i)){
      sum ++;
      b[i] = 1;    
    }
  }
  ll ans = sum;
  
  //watcharr(a, n);
  //watcharr(b, n);
  
  for (int i = 1; i < n-1; ++i){
    int temp = a[i];
    
    a[i] = a[i-1];
    ans = min(ans, sum - b[i] - b[i-1] - b[i+1] + 
            isvalley(i-1) + ishill(i-1) + 
            isvalley(i) + ishill(i) +
            isvalley(i+1) + ishill(i+1) );
    
    a[i] = a[i+1];
    ans = min(ans, sum - b[i] - b[i-1] - b[i+1] + 
            isvalley(i-1) + ishill(i-1) + 
            isvalley(i) + ishill(i) +
            isvalley(i+1) + ishill(i+1) );
    
    a[i] = temp;
  }
  
  cout << ans << endl;
  
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