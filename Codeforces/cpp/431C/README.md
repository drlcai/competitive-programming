Difficulty: 1600

This problem can be solved by dinamic programming.

It is straightforward to see that we need an array of size `n + 1`. 
`table[i]` means the number of paths if the sum is `i`. We need two tables, one is for only
considering `k`, the other is for considering the existence of `d`.

My first implementation creates such two tables. The first one is a quick implementation for easier case. 
In the second one, for the `tablewithlow[i]`, 
we need to sum over `tablewithlow[i-1] + ,...,+ tablewithlow[i - d + 1] + table[i - d] + table[i - d - 1] + ... + table[i - k]`. 

Note that `d` is always smaller than `k`, but `k` and `n` are not determined. So we need to consider that in our for loops. 
To secure the right subscript,
in this problem I did 3 cases to avoid it: `n<k, n=k, n>k`. 

=================

Below is the official tutorial. It is cleverer because it uses a 2-d table and also the code has some nice tricks for me to learn:
* Its two different dp tables are not the same as mine. They clearly distinguish the number of ways to "have" an edge greter than `d` and "not have".
* `add(int &a, int b)` is a quick/shorter way to update `dp[i][]`.
* Use `if(i - j < 0)` to clearly avoid thinking too much about `n ? k`.

By doing the good things above the standard solution is better than mine in many ways. 

Let's `dp[n][is]` — number of ways with length equals to `n` in `k`-tree, where if `is = 1` — there is exists edge with length at least `d`, `is = 0` — 
lengths of all edges less than `d`. Initial state `dp[0][0] = 1`.

Transition — iterate all edges which can be first on the way in `k`-tree, then problem transform to the same, 
but with less length of the way (because subtree of vertex son is the `k`-tree).

`dp[n][0] = dp[n-1][0] + ... + dp[n-min(d-1,n)][0]`
`dp[n][1] = dp[n-1][1] + ... + dp[n-min(d-1,n)][1] + (dp[n-d][0] + dp[n-d][1]) + ... + (dp[n-min(n,k)][0] + dp[n-min(n,k)][1])`

Complexity: `O(nk)`
Notice that this solution can be easy midify to O(N) complexity, only precalc partial sums. But it is not neccesary to solve this problem in such way.

```cpp
#include <iostream>
#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
int dp[100][2];
 
void add(int &a, int b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}
 
int main(int argc, char ** argv)
{
    int n, k, d;
    cin >> n >> k >> d;
    dp[0][0] = 1;
    dp[0][1] = 0;
    
    for(int i = 1 ; i <= n ; ++i)
    {
        dp[i][0] = dp[i][1] = 0;
        
        for(int j = 1 ; j <= k ; ++j)
        {
            if(i-j < 0) break;
            
            if(j < d)
            {
                add(dp[i][0], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
            else
            {
                add(dp[i][1], dp[i-j][0]);
                add(dp[i][1], dp[i-j][1]);
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}
```
