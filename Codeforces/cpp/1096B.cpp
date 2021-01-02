#include <iostream>
#include <string>

using namespace std;

int main(){
  long long n;
  string s;
  
  cin >> n >> s;
  
  long long start = 1;
  
  char sc = s[0];
  char ec = s[n - 1];
  
  for(long long i = 1; i < n; i ++){
    if(s[i] == sc){
      start ++;
      continue;
    }else{
      break;
    }
  }
  
  long long end = 1;
  
  for(long long i = n-2; i >= 0; i --){
    if(s[i] == ec){
      end ++;
      continue;
    }else{
      break;
    }
  }
  
  long long res = 0;
  if(sc == ec){
    res = (start + end + start * end + 1) % 998244353 ;
  }else{
    res = (start + end + 1) % 998244353 ;
  }
  
  cout << res << endl;
}