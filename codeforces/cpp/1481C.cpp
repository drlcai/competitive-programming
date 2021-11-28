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
#define OOO 1000000010
const double pi = acos(-1.0);


#define read(type) readInt<type>()

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
  int n, m;
  
  cin >> n >> m;
  
  VI A, B, C;
  
  FOR(i, 0, n, 1){
    int a;
    cin >> a;
    A.push_back(a);
  }
  
  map<int, VI> table;
  
  FOR(i, 0, n, 1){
    int b;
    cin >> b;
    B.push_back(b);
    
    if (B[i] != A[i]){
      auto it = table.find(B[i]);
      if (it != table.end()){
        table[B[i]].push_back(i);
      }else{
        VI vec;
        vec.push_back(i);
        table[B[i]] = vec;
      }
    }
    
    
  }
  
  FOR(i, 0, m, 1){
    int c;
    cin >> c;
    C.push_back(c);
  }
  
  int cm = C[m-1];
  int x = -1;
  
  if (table.find(cm) != table.end()){
    x = table.find(cm)->second.back();
    table.find(cm)->second.pop_back();
  }else{
    FOR(i, 0, n, 1){
      if(B[i] == cm){
        x = i;
        break;
      }
    }
  }
  
  if(x == -1){
    puts("NO");
    return;
  }
  
  // if the last painter has a plank to paint
  VI ans(m);
  
  ans[m-1] = x;
  
  FOR(i, 0, m-1, 1){
    if(table.find())
    
		if((int)g[c[i]].size() == 0){
		 	ans[i] = last;
		}
		else{
			ans[i] = g[c[i]].back();
			g[c[i]].pop_back();
		}
	}
  
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