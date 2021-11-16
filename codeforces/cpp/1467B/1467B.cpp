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
typedef vector<bool> VB;
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

int solve(int n){
  if(n <= 2){
    while(n --> 0){
      int x;
      cin >> x;
    }
    return 0;
  }
  
  VI table(n);
  VI yn(n);
  FOR(i, 0, n, 1){
    cin >> table[i];
    //cout << table[i];
  }
  
  int all = 0;
  FOR(i, 1, n-1, 1){
    if (table[i] > table[i-1] && table[i] > table[i+1]){
      yn[i] = 1;
      all ++;
    }else if(table[i] < table[i-1] && table[i] < table[i+1]){
      yn[i] = -1;
      all ++;
    }
  }
  
  if (all == 0)
    return 0;
  
  int dec = 0;
  
  FOR(i, 1, n-1, 1){
    
    if(yn[i] == 0)
      continue;
    
    int check = abs(yn[i-1]) + abs(yn[i+1]);
    
    if(check == 0)
      dec = max(1, dec);
    else if(check == 2){
      dec = max(3, dec);
    }else{ // check == 1
      int y, nt;
      if(yn[i-1] != 0){ // YYN
        y = table[i-1];
        nt = table[i+1];
        
        if(yn[i] == 1){ // hill
          if( y < nt && i + 2 < n && table[i + 1] != table[i + 2]){
            dec = max(1, dec);
          }else{
            dec = max(2, dec);
          }
        }else{
          if ( y > nt && i + 2 < n && table[i + 1] != table[i + 2]){
            dec = max(1, dec);
          }else{
            dec = max(2, dec);
          }
        }
      }else{ // NYY
        y = table[i + 1];
        nt = table[i - 1];
        
        if(yn[i] == 1){
          if (y < nt && i - 2 >= 0 && table[i - 1] != table[i - 2]){
            dec = max(1, dec);
          }else{
            dec = max(2, dec);
          }
        }else{
          if ( y > nt && i - 2 >= 0 && table[i - 1] != table[i - 2]){
            dec = max(1, dec);
          }else{
            dec = max(2, dec);
          }
        }
      }
      
    }
  }
  
  return all - dec;
  
  
}


int main()
{
  int tc;
  SCD(tc);
  
	while (tc --> 0){
    int n;
    cin >> n;
    int res = solve(n);
    cout << res << endl;
  }
  
	
}
/********  Main() Ends Here *************/