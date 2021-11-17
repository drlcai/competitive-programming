#include <bits/stdc++.h>
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
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}

// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
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
 
 
 
ll n, m, q, k, l, r, x, y, z, idx;
const ll template_array_size = 1e6 + 17928;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
 
 
 bool ist1(string str){
	 
	 bool flag = false;
	 
	 for (int i = 0; i < str.size(); ++i){
		 if (!flag && isdigit(str[i]) ) {
			 flag = true;
		 } 
		 
		 if (flag && isalpha(str[i]) ){
			 return false;
		 }
	 }
	 return true;
 }

string cv1to2(string str) {
	idx = 0;
	
	string s1, s2;
	
	while( isalpha(str[idx]) ){
		idx ++;
	}
	s1 = str.substr(0, idx);
	s2 = str.substr(idx, str.size());
	
	x = 0;
	for (int i = 0; i < s1.size(); ++i){
		x = ((s1[i] - 'A') + 1) + (26 * x);
	}

	s1 = to_string(x);
	
	return "R" + s2 + "C" + s1;
} 

string cv2to1(string str){
	idx = 0;	
	
	while(str[idx] != 'C'){
		idx ++;
	}
	
	string row = str.substr(1, idx-1);
		
	string col = str.substr(idx+1, str.size());
	
	x = stoi(col);
	string coln = "";
	
	while (x != 0){		
		int t = x % 26;
		if (t == 0){
			x -= 26;
			coln = 'Z' + coln;
		}else{
			x -= t;
			coln = char('A' + t - 1) + coln;
		}
		
		x = x / 26;
	}
	
	return coln + row;
}
 
void solve(int tc = 0) {
	string str;
	cin >> str;
	
	if (ist1(str)){
		cout << cv1to2(str) << endl;
	}else{
		cout << cv2to1(str) << endl;
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