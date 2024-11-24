// C:\msys64\mingw64\include\c++\13.1.0\x86_64-w64-mingw32\bits
#include <bits/stdc++.h>

#include <atcoder/all>

#include <iostream>

using namespace std;
using namespace atcoder;

////////////////////////////////////////////////////////////
// Display
////////////////////////////////////////////////////////////

template <typename T>
void print_vec(const std::vector<T> &vec, bool show_id = true)
{
  for (int i = 0; i < vec.size(); i++)
  {
    cout << i << "\t";
  }
  cout << "\n";

  for (const auto &elem : vec)
  {
    cout << elem << "\t"; // Print each element followed by a space
  }
  cout << '\n'; // Print a newline after printing all elements
}

template <typename T>
void print_vec_2d(const std::vector<std::vector<T>> &vec, bool show_id = true)
{

  if (vec.size() == 0)
  {
    return;
  }

  long long m = vec.size();
  long long n = vec[0].size();

  if (show_id)
  {
    cout << " " << "\t";
    for (int i = 0; i < n; i++)
    {
      cout << i << "\t";
    }
  }
  cout << "\n";

  long long row_id = 0;
  for (const auto &row : vec)
  {
    if (show_id)
    {
      cout << row_id << "\t";
      row_id++;
    }

    for (const auto &elem : row)
    {
      cout << elem << "\t"; // Print each element with a space
    }
    cout << '\n'; // Newline after each row
  }
}

////////////////////////////////////////////////////////////
// Maths
////////////////////////////////////////////////////////////

const long long MOD = 1e9 + 7;
const long long MAXN = 1e6; // Max value of n, adjust as needed

std::vector<long long> fact(MAXN + 1), inv_fact(MAXN + 1);

// Function to compute x^y % MOD using binary exponentiation
long long mod_pow(long long x, long long y, long long mod)
{
  long long res = 1;
  while (y > 0)
  {
    if (y % 2 == 1)
    {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    y /= 2;
  }
  return res;
}

// Function to precompute factorials and inverse factorials
void precompute_factorials()
{
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= MAXN; ++i)
  {
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv_fact[MAXN] = mod_pow(fact[MAXN], MOD - 2, MOD); // Fermat's Little Theorem for inverse
  for (int i = MAXN - 1; i >= 1; --i)
  {
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
  }
}

// Function to compute n choose k modulo MOD
// remember to use it we need to call precompute_factorials first.
long long nCk(long long n, long long k)
{
  if (k > n)
    return 0;
  return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

////////////////////////////////////////////////////////////
////////////////////   SOLUTION   //////////////////////////
////////////////////////////////////////////////////////////

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  if (n < 2)
  {
    cout << 0;
    return;
  }

  int ml = 0;

  int stt = 0;

  map<int, int> last;

  for (int i = 0; i < n; i++)
  {
    // if stt to i is even
    if ((i - stt) % 2 == 1)
    {
      if (a[i] != a[i - 1])
      {
        stt = i;
      }
      else
      {
        ml = max(ml, i - stt + 1);
      }
    }
    // if stt to i is odd length
    else
    {
      if (last[a[i]] > stt)
      {
        if (last[a[i]] == i-1)
        {
          stt = i-1;
          ml = max(ml, 2);
        }else{
          stt = last[a[i]] + 1; // I got it wrong, it should be 1 after last[a[i]], I wrote i
        }
      }

    }

    last[a[i]] = i;
  }

  cout << ml;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

int main()
{
  cin.tie(0);

  solve();
}