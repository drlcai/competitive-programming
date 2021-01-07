/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef pair<string, string> PSS;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

#define watch(x) cout << (#x) << " is " << (x) << endl;
/********** Main()  function **********/

string parseR(int t, string r){
  string res;
  if(t == 0){
    res = "R" + r;
  }else{
    res = r;
  }
  return res;
}

string parseC(int t, string c){
  string res = "";
  if (t == 0){ // AB
    int sum = 0;
    FOR(i, 0, c.size(), 1){
      sum = sum * 26 + (c[i] - 'A' + 1);
    }
    res = "C" + to_string(sum);
  }
  else{ //23
    int ic = stoi(c);
    while(ic != 0){
      int r = (ic - 1) % 26;
      res = char(('A' + r)) + res;
      ic = (ic - 1) / 26;
    }
  }
  return res;
}

string parse(string s){
  string res;
  if (s[0] != 'R' || isalpha(s[1])){ // BC23, RA23 (type 0)
    string col = "";
    string row = "";
    int ptr = 0;
    while(isalpha(s[ptr])){
      col += s[ptr++];
    }
    while(ptr < s.size()){
      row += s[ptr++];
    }
    res = parseR(0, row) + parseC(0, col);
  }
  else{ // R23 (type 0) or R12C23 (type 1)
    int ptr = 1;
    string row = "";
    while (isdigit(s[ptr]) && ptr < s.size()){
      row += s[ptr];
      ptr ++;
    }
    if (ptr == s.size()){ // type 0
      res = parseR(0, row) + parseC(0, "R");
    }else{ // type 1
      // ptr now points to C
      ptr ++;
      string col = "";
      while(ptr < s.size()){
        col += s[ptr++];
      }
      res = parseC(1, col) + parseR(1, row);
    }
  }
  return res;
}

void solve(string s) {
  string res = parse(s);

  cout << res << endl;
}

int main()
{
  int tc;
  SCD(tc);
  
	while (tc --> 0){
    string s;
    cin >> s;
    solve(s);
  }
  
	
}
/********  Main() Ends Here *************/