#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int temp = 0;
  int* diff = new int[n];
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    diff[i] = num - temp;
    temp = num;
  }
  
  // for (int i = 0; i < n; i++) {
  //   cout << diff[i] << " ";
  // }
  // cout << endl;

  vector<int> res;
  for (int i = n - 1; i > 0; i--) {
    int ifinres = true;
    for (int j = 0; j < i; j++) {
      if (diff[j] != diff[n - i + j]) {
        ifinres = false;
        break;
      }
    }
    if (ifinres) res.push_back(n - i);
  }
  
  res.push_back(n);
  
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}