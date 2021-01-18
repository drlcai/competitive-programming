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
typedef vector<int64> VI64;

#define watch(x) cout << (#x) << " is " << (x) << endl;

/********** Main()  function **********/
/*
  There are different cases for Kadane's algorithm.
  1. We can choose empty slice, i.e., if we cannot create
      positive sum, we can get 0 as the maximum.
  2. We must choose at least one number.
  
  Regarding the requirement, there are 2 cases.
  1. We ask for the maximum sum ending at position [i].
  2. We ask for the maximum sum over the entire array.
*/


// We can choose empty slice.
// We can always use 0 as best if all numbers are negative.
int kadaneWithEmpty(VI &A) {
  int n = A.size();
  int best_sum = 0;  // or: float('-inf')
  int current_sum = 0;
  
  VI max_ending(n); // Used to store the local best till pos i
  
  for (int i = 0; i < A.size(); ++i){
    current_sum = max(0, current_sum + A[i]); // maximum
    max_ending[i] = current_sum;
    best_sum = max(best_sum, current_sum);
  }
  return best_sum;
}

// We can't choose empty slice.
// In this case, best_sum should be initialized to INT_MIN
// because negative numbers are allowed.
// Another thing is in the for loop, it should be
// current_sum = max(A[i], current_sum + A[i]).
// This is DP. At position i, if A[i] is better than current_sum + A[i],
// then the local best till A[i] should be itself.
int kadaneWithoutEmpty(VI &A) {
  int n = A.size();
  int best_sum = INT_MIN;  // or: float('-inf')
  int current_sum = 0;
  
  VI max_ending(n); // Used to store the local best till pos i
  
  for (int i = 0; i < A.size(); ++i){
    current_sum = max(A[i], current_sum + A[i]); // maximum
    max_ending[i] = current_sum;
    best_sum = max(best_sum, current_sum);
  }
  return best_sum;
}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	#endif

  VI A{-2, -3, 4, -1, -2, 1, 5, -3};
  
  int result = kadaneWithEmpty(A);
  cout << result;
	
	return 0;
}
/********  Main() Ends Here *************/