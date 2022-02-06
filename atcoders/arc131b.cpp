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


char choose(vector<char> colors){
  char ans;
  bool test[] = {true,true,true,true,true};
  for (int i = 0; i < colors.size(); ++i){
    if (colors[i] == '.'){
      continue;
    }
    
    test[ (colors[i] - '1') ] = false;
  }
  
  for (int i = 0; i < 5; ++i){
    if(test[i]){
      ans = (char)('1' + i);
      break;
    }
  }
  
  return ans;
}

void solve(int tc = 0) {
	int H,W;
  cin >> H >> W;
  
  vector< vector<char> > table(H);
  
  for (int i = 0; i < H; ++i){
    vector<char> temp(W);
    table[i] = temp;
  }
  
  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      cin >> table[i][j];
    }
  }
  
  int dRow[] = { 0, 1, 0, -1 };
  int dCol[] = { -1, 0, 1, 0 }; 

  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      if (table[i][j] == '.'){
        vector<char> colors;
        for (int d = 0; d < 4; ++d){
          int di = i + dRow[d];
          int dj = j + dCol[d];
          
          if (di >= 0 && di < H && dj >=0 && dj < W){
            colors.push_back(table[di][dj]);
          }
        }
        
        table[i][j] = choose(colors);
        
      }
    }
  }
  
  
  // watch
  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      cout << table[i][j];
    }
    cout << endl;
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
	//cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef leran_cai_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}