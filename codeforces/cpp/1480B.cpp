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
typedef pair<int64, int64> PII64;
typedef vector<int64> VI64;

#define watch(x) cout << (#x) << " is " << (x) << endl;

/********** Main()  function **********/
void solve() {
  int64 A, B, n;
  cin >> A >> B >> n;
  
  VI64 a,b;
  FOR(i, 0, n, 1){
    int64 x;
    cin >> x;
    
    a.push_back(x);
  }
  
  FOR(i, 0, n, 1){
    int64 y;
    cin >> y;
    b.push_back(y);
  }
  
  priority_queue<PII64, vector<PII64>, greater<PII64> > pq;
  
  FOR(i, 0, n, 1){
    int64 natt = b[i] / A + (b[i] % A != 0);
    //watch(natt);
    int64 dmg = natt * a[i];
    
    pq.push(make_pair( (int64)a[i], dmg));
  }
  
  int kill = 0;
  while (!pq.empty()){
      //cout << pq.top().first << " ";
      PII64 monster = pq.top();
      watch(monster.first);
      watch(monster.second);
      pq.pop();
      if(B > monster.second){
        kill ++;
        B -= monster.second;
        //watch(B);
      }else{
        if(B > monster.second - monster.first)
          kill ++;
        
        //watch(B);
        break;
      }
      
  }
  
  if(kill >= n){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  
  
  
    
}

int main()
{

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// //freopen("output.txt","w",stdout);
	// #endif


	int tc;
  SCD(tc);
  
	while (tc --> 0){
    solve();
  }
	// int tc;
	// tc = read(int);

	// while(tc--){
	// 	write(tc);
	// }
	return 0;
}
/********  Main() Ends Here *************/