#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  string s;
  cin >> s;
  
  bool yes = false;
  for(int i = 0; i < 5; i ++){
    string temp;
    cin >> temp;
    if (temp[0] == s[0] || temp[1] == s[1]){
      cout << "YES";
      yes = true;
      break;
    }
  }
  
  if(!yes) cout << "NO";
  
  return 0;
}
