#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    long long k, s;
    cin >> k >> s;
    long long vol = 0;
    vector<long long> vols(k);
    
    for(int i = 0; i < k; i ++){
        cin >> vols[i];
        vol += vols[i];
    }
    
    sort(vols.begin(), vols.end());
    
    if(vol < s)
        cout << -1;
    else{
        long long more = vol - k * vols[0];
        if (more >= s){
            cout << vols[0];
        }else{ // more < s, s - more >= 1
            long long need = s - more;
            cout << vols[0] - (need - 1) / k - 1;
        }
    }
    
    
}