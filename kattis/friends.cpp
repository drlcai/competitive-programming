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
	//freopen((filename + ".out").c_str(), "w", stdout);
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

unsigned int graph[150][4];
unsigned int cliques[1010][4];

void add_node(unsigned int* nset, int v){
  int slot = v / 32;
  int shift = v % 32;
  
  nset[slot] |= 1 << (31 - shift);
}

// check if b can cancel 1s in a
bool issubset(unsigned int a[4], unsigned int b[4]){
  unsigned int temp[4] = {0,0,0,0};
  
  for (int i = 0; i < 4; ++i){
    temp[i] = a[i] & b[i];
  }
  
  // I made a mistake here, very serious
  unsigned long long sum = 0;
  for (int i = 0; i < 4; ++i){
    sum += a[i] - temp[i];
  }
  
  return (sum == 0);
}

bool in_set(unsigned int s[4], int v){
  unsigned int temp[4] = {0,0,0,0};
  add_node(temp, v);
  return issubset(temp, s);
}


// find the intercection of a and b, then save it to c
void s_intercection(unsigned int a[4], unsigned int b[4], unsigned int* c){
  for (int i = 0; i < 4; i ++){
    c[i] = a[i] & b[i];
  }
}

bool maximal(unsigned int s[4], int n){
  for (int i = 0; i < n; ++i){
    // i not in s, and i connects to all s, s subset of graph[i]
    // then return false
    if ( !in_set(s , i) && issubset(s, graph[i]) ){
      return false;
    }
  }
  
  return true;
}

bool isequal(unsigned int a[4], unsigned int b[4]){
  for (int i = 0; i < 4; i++){
    if (a[i] != b[i])
      return false;
  }
  return true;
}

bool ispresent(unsigned int a[4], int k){
  for (int i = 0; i < k; ++i){
    if(isequal(a, cliques[i]))
      return true;
  }
  
  return false;
}

int get_clique(int n){
  if (n == 1){
    // set 0 node in cliques[0]
    add_node(cliques[0], 0);
    return 1;
  }
  
  int res = get_clique(n-1);
  
  if (res > 1000)
    return res;
  
  int newres = res;
  int newnode = n-1;

  
  for (int i = 0; i < res; ++i){
    // check cliques[i] with node n
    // if n connects with all nodes in cliques[i], add in; cliques[i] is a subset of N[newnode]
    // this does not change res
    // update present with one more 0
    if ( issubset(cliques[i], graph[newnode] ) ){
      add_node(cliques[i], newnode);
    }
    // if n doesn't connects with all nodes in cliques[i]
    // find the intersection of cliques[i] and N[n]
    // create [intersection] + [n], as cliques[newres]
    // check if it is maximal, if yes, then increase newres, and this new set is valid
    // if it is not maximal, move on, doesn't change newres
    else{
      unsigned int intersect[4] = {0,0,0,0};
      s_intercection(cliques[i], graph[newnode], intersect);

      add_node(intersect, newnode);

      
      if ( !ispresent(intersect, newres) && maximal(intersect, n) ){
        
        for (int w = 0; w < 4; ++w){
          cliques[newres][w] = intersect[w];
        }
        newres ++;
      }
    }
    
    if (newres > 1000){
      return newres;
    }
  }
  
  return newres;
}


void solve() {
  memset(graph, 0, sizeof(graph));
  memset(cliques, 0, sizeof(cliques));

  // initilize and add in selfloop
  for(int i = 0; i < n; ++i){
    add_node(graph[i], i);
  }
  
  for (int i = 0; i < m; ++i){
    cin >> x >> y;
    x--; y--;
    add_node(graph[x], y);
    add_node(graph[y], x);
  }

  int k = get_clique(n);
  
  if (k <= 1000){
    cout << k << endl;
  }else{
    cout << "Too many maximal sets of friends." << endl;
  }
  
}
 
int main() {
	#ifdef leran_cai_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef leran_cai_local
		// usaco("");
	#endif
	
	//usaco("a");
  //freopen("a_31.out", "r", stdin);
  //freopen("a.in", "r", stdin);
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
  while (cin >> n >> m)
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