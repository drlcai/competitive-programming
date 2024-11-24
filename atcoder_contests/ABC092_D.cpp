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
void print_vec(const std::vector<T> &vec)
{
  for (const auto &elem : vec)
  {
    std::cout << elem << " "; // Print each element followed by a space
  }
  std::cout << "\n"; // Print a newline after printing all elements
}

template <typename T>
void print_vec_2d(const std::vector<std::vector<T>> &vec)
{
  for (const auto &row : vec)
  {
    for (const auto &elem : row)
    {
      std::cout << elem << " "; // Print each element with a space
    }
    std::cout << "\n"; // Newline after each row
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
////////////////////////////////////////////////////////////

void solve()
{
  int a, b;
  cin >> a >> b;

  int k = 50;

  vector<vector<char>> table(k * 2, vector<char>(k * 2, '#'));

  for (int i = k; i < 2 * k; i++)
  {
    fill(table[i].begin(), table[i].end(), '.');
  }


  // change black to white
  int wc = 1;
  int bc = 1;

  bool keepgoing = true;
  for (int i = 0; i < k - 1; i+=2)
  {
    for (int j=0; j<2*k;j+=2)
    {
      if (wc == a)
      {
        keepgoing = false;
        break;
      }
      table[i][j] = '.';
      wc++;
    }
    if (!keepgoing)
      break;
  }

  // change white to black
  keepgoing = true;
  for (int i = k + 1; i < 2 * k; i+=2)
  {
    for (int j=0; j<2*k;j+=2)
    {
      if (bc == b)
      {
        keepgoing = false;
        break;
      }
      table[i][j] = '#';
      bc++;
    }
    if (!keepgoing)
      break;
  }

  cout << 2*k << " " << 2*k <<"\n";
  for (const auto &row : table)
  {
    for (const auto &elem : row)
    {
      std::cout << elem; // Print each element with a space
    }
    std::cout << "\n"; // Newline after each row
  }
}

int main()
{
  cin.tie(0);

  solve();
}