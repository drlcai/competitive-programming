#include "bits/stdc++.h"
using namespace std;

#define printv(v) { for(int i = 0; i < v.size(); ++i){cout << v[i] << " "; }cout << endl; }

void solve(int tc = 0) {
	int x;
    string s;

    cin >> x >> s;
    
    map<string, int> m;
    
    for (int i = 0; i < x-1; i++){
        string ss = s.substr(i, 2);
        m[ss] = 1;
    }
    cout << m.size() << endl;
}


int main()
{
    int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
}