#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int res = INT_MAX;
    for(int i =0; i < n; i++){
        if(arr[i] + (n-i-1) < res) res = arr[i] + (n-i-1);
    }
    res = min(res, n);
    cout << res;

}