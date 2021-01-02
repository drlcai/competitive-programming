#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  
  int sum = 0;
  int maxa = -1;
  for(int i = 0; i < n; i ++){
    int m;
    cin >> m;
    sum += m;
    maxa = maxa < m ? m : maxa;
  }
  
  sum *= 2;
  
  int k = sum/n + 1;
  
  cout << max(k, maxa) << endl;
}