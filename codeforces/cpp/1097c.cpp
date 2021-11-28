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



void solve(int tc = 0) {
  cin >> n;
  map<int, int> table;
  
  for (int i = 0; i < n; ++i){
    cin >> s;
    
    // check left-needed, right-needed
    int ln = 0;
    int rn= 0;

    int lcnt = 0;
    
    for (int i = 0; i < s.size(); ++i){
      if (s[i] == '(') lcnt --;
      if (s[i] == ')') lcnt ++;
      if (lcnt > 0) ln = max(ln, lcnt);
    }
    
    int rcnt = 0;
    for (int i = s.size() - 1; i >= 0; --i){
      if (s[i] == '(') rcnt ++;
      if (s[i] == ')') rcnt --;
      if (rcnt > 0) rn = max(rn, rcnt);
    }
    
    // cout << ln << " " << rn << endl;
    
    if (ln == 0 || rn == 0){
      int sign;
      if (ln == 0) sign = -1;
      if (rn == 0) sign = 1;
      
      int key = (ln + rn) * sign;
      
      auto it = table.find(key);
      if (it == table.end())
        table[key] = 1;
      else
        table[key] ++;
    }
  }
  
  // cout << "pass" << endl;
  // watchmap(table);
  
  int ans = 0;
  while(!table.empty()){
    auto it = table.begin();
    
    if (it->first == 0){
      ans += it->second / 2;
      table.erase(0);
    }else{
      int key = it->first;
      auto itt = table.find(-key);
      if (itt != table.end()){
        ans += min(it->second, itt->second);
        table.erase(-key);
      }
      
      table.erase(key);
    }
    
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
	// cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef leran_cai_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}
