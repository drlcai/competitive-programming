#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int m;
  cin >> m;
  
  int count[4];
  for(int i = 0; i < m; i++){
    int temp;
    cin >> temp;
    count[temp - 1] ++;
  }
  
  int res = 0;
  res += count[3];
  
  res += count[1]/2;
  count[1] %= 2;
  count[0] = max(0, count[0] - 2 * count[1]);
  res += count[1];
  
  res += count[2];
  count[0] = max(0, count[0] - count[2]);
  res += count[0] % 4 == 0 ? count[0]/4 : count[0]/4 + 1;
  
  cout << res << endl;
  
}