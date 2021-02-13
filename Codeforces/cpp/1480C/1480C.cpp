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
VI N(100001,0);

void query(int k){
  cout << "? " << k << endl;
  cout.flush();
  cin >> N[k];
}

void answer(int k){
  cout << "! " << k << endl;
}

int main()
{
  int n;
  cin >> n;
  
  if (n == 1){
    answer(1);
    return 0;
  }
  
  query(1);
  query(2);
  
  if (N[2] > N[1]){
    answer(1);
    return 0;
  }
  
  query(n);
  query(n-1);
   
  if (N[n-1] > N[n]){
    answer(n);
    return 0;
  }
  
  int lo = 1;
  int hi = n;
  
  while(lo < hi){
    int m = (lo + hi) / 2;
    
    if (N[m] == 0)
      query(m);
  
    if (N[m-1] == 0)
      query(m-1);
    
    if (N[m+1] == 0)  
      query(m+1);
    
    if (N[m] < min(N[m-1], N[m+1])){
      answer(m);
      return 0;
    }
    
    if(N[m-1] < N[m+1]){
      hi = m;
    }else{
      lo = m;
    }
    
  }
  
	return 0;
}
/********  Main() Ends Here *************/