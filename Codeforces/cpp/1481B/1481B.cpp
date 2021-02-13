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

void solve(){
  int n, k;
  
  cin >> n >> k;
  
  VI list;
  
  FOR(i, 0, n, 1){
    int h;
    cin >> h;
    list.push_back(h);
  }
  
  // watch(n);
  // watch(k);
  // cout << "watch list: ";
  // FOR(i, 0, n, 1){
  //   cout << list[i] << " ";
  // }
  // cout << endl;
  
  // simulation
  while (true){
    // for one ball    
    int ptr = 0;
    
    while(ptr < n - 1){
      if(list[ptr] >= list[ptr+1]){
        // if the ball can go, then go forward.
        ptr ++;
      }else{
        // if the ball can't go, then k --
        // if this is the last ball, return ptr
        // if this is not the last ball, update list[ptr]++
        // then break ptr loop, let the next ball coime
        k --;
        list[ptr] += 1;
        if(k == 0){
          //cout << "stop here: " ;
          cout << ptr + 1 << endl;
          return;
        }
        break;
      }    
    }

    
    // if the ball goes to the end, break this big loop and return -1
    if (ptr == n - 1){
      break;
    }
    
  }
  
  cout << -1 << endl;
  return;
  
}

int main()
{
  int tc;
  SCD(tc);
  
	while (tc --> 0){
    solve();
  }
  
	
}
/********  Main() Ends Here *************/