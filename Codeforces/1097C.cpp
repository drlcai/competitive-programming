#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;

  cin >> n;

  map<int, int> table;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int len = s.size();
    int count = 0;
    bool leftcheck = true;
    bool rightcheck = true;

    for (int j = 0; j < len; j++) {
      if (s[j] == '(') count--;
      if (s[j] == ')') count++;
    }

    // leftcheck
    int tempcount = 0;
    for (int j = 0; j < len; j++) {
      if (s[j] == '(') tempcount--;
      if (s[j] == ')') tempcount++;
      if (tempcount > 0) {
        leftcheck = false;
        break;
      }
    }

    // rightcheck
    tempcount = 0;
    for (int j = len - 1; j >= 0; j--) {
      if (s[j] == '(') tempcount--;
      if (s[j] == ')') tempcount++;
      if (tempcount < 0) {
        rightcheck = false;
        break;
      }
    }

    if( (count < 0 && leftcheck) || (count > 0 && rightcheck) || (count == 0 && leftcheck && rightcheck)){
      map<int, int>::iterator it = table.find(count);
      if (it != table.end()) {
        it->second++;
      } else {
        table.emplace(count, 1);
      }
    }
  }

  // calculate the result
  int res = 0;
  int zero = 0;
  for (map<int, int>::iterator it = table.begin(); it != table.end(); it++) {
    //cout << it->first << " " << it->second << endl;
    int code = it->first;
    int count = it->second;

    if (code == 0) {
      zero = count / 2;
      continue;
    }

    map<int, int>::iterator itt = table.find(-code);
    if (itt != table.end()) {
      res += min(count, itt->second);
    }
  }

  res = res / 2 + zero;
  cout << res;

  return 0;
}

/*

3
)(
)(
()

2
())(
()

2
)((()
)

2
()))(()
())((()

*/