#include <iostream>

using namespace std;

int main(){
  long long n, x, y;
  cin >> n >> x >> y;
  
  long long dw = max(x - 1, y - 1);
  long long db = max(n - x, n - y);
  
  if(dw <= db){
    cout << "White" << endl;
  }else{
    cout << "Black" << endl;
  }
  
}