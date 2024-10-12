// C:\msys64\mingw64\include\c++\13.1.0\x86_64-w64-mingw32\bits
#include <bits/stdc++.h>

#include <atcoder/all>

#include <iostream>

using namespace std;
using namespace atcoder;

////////////////////////////////////////////////////////////
// Display
////////////////////////////////////////////////////////////

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


////////////////////////////////////////////////////////////
// Maths
////////////////////////////////////////////////////////////

const long long MOD = 1e9+7;
const long long MAXN = 1e6;  // Max value of n, adjust as needed

std::vector<long long> fact(MAXN + 1), inv_fact(MAXN + 1);

// Function to compute x^y % MOD using binary exponentiation
long long mod_pow(long long x, long long y, long long mod) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}

// Function to precompute factorials and inverse factorials
void precompute_factorials() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MAXN] = mod_pow(fact[MAXN], MOD - 2, MOD);  // Fermat's Little Theorem for inverse
    for (int i = MAXN - 1; i >= 1; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

// Function to compute n choose k modulo MOD
// remember to use it we need to call precompute_factorials first.
long long nCk(long long n, long long k) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


void solve()
{
  precompute_factorials();
  int h,w,a,b;
  cin>>h>>w>>a>>b;

  long long ans = 0;
  
  for (int i=b;i<w;i++){
    long long tmp = (nCk(h-a-1+i, h-a-1) % MOD * nCk(w-1-i+a-1, a-1)) % MOD;
    ans = (ans + tmp) % MOD;
  }
  
  cout << ans;
  
}

int main()
{
  cin.tie(0);

  solve();
}