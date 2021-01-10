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
typedef vector<int64> VI64;


#define watch(x) cout << (#x) << " is " << (x) << endl;
/********** Main()  function **********/

void solve(){
  
  VI64 table[3];
  
  FOR(i, 0, 3, 1){
    int64 len;
    cin >> len;
    table[i].resize(len);
  }
  
  FOR(i, 0, 3, 1){
    FOR(j, 0, table[i].size(), 1){
      cin >> table[i][j];
    }
  }
  
  FOR(i, 0, 3, 1){
    sort(table[i].begin(), table[i].end());
  }
    
  VI64 first(3);  
  VI64 tail(3);
  
  FOR(i, 0, 3, 1){
    first[i] = table[i][0];
    int64 sum = 0;
    FOR(j, 1, table[i].size(), 1){
      sum += table[i][j];
    }
    tail[i] = sum;
  }
  
  VI64 ntable;
  
  int c = 0;
  
  FOR(i, 0, 3, 1){
    ntable.push_back(first[i]);
    if (tail[i] == 0){
      c += 1;
    }else{
      ntable.push_back(tail[i]);
      c += 2;
    }
  }
  
  int64 res = 0;
  
  sort(ntable.begin(), ntable.end());
  
  VI64 nntable;
  int idx;
  
  switch(c){
    case 3:
      res = ntable[2] + ntable[1] - ntable[0];
      break;
    case 4:
      FOR(i, 0, 3, 1){
        if(tail[i] == 0){
          nntable.push_back(first[i]);
        }else{
          nntable.push_back(first[i] + tail[i]);
        }
      }
      sort(nntable.begin(), nntable.end());
      res = nntable[2] + nntable[1] - nntable[0];
      break;
    case 5:
      FOR(i, 0,3,1){
        if (tail[i] == 0){
          idx = i;
          break;
        }
      }
      FOR(i,0,3,1){
        if(i != idx){
          nntable.push_back(first[i]);
          nntable.push_back(tail[i]);
        }
      }
      sort(nntable.begin(), nntable.end());
           
      if(nntable[0] + nntable[1] < first[idx]){
        res = nntable[3] + nntable[2] + first[idx] - nntable[1] - nntable[0];
      }else{
        res = nntable[3] + nntable[2] + nntable[1] + nntable[0] - first[idx];
      }
      
      break;    
    default:
      res -= ntable[0] + ntable[1];
      FOR(i, 2, ntable.size(),1){
        res += ntable[i];
      }
      break;
  }
  cout << res << endl;
  
}

int main()
{
  solve();
}
/********  Main() Ends Here *************/