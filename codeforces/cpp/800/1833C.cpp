#include "bits/stdc++.h"
using namespace std;

#define print(v) { for(int i = 0; i < v.size(); ++i){cout << v[i] << " "; }cout << endl; }

void solve(int tc = 0) {
	int x;
    cin >> x;

    vector<int> v(x);

    for (int i = 0; i < x; i ++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // print(v);

    if (v[0] % 2 == 1){
        cout << "YES" << endl;
        return;
    }

    for (int i = 1; i < x; i++){
        if (v[i] % 2 == 1){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}


int main()
{
    int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
}