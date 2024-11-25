// C:\msys64\mingw64\include\c++\13.1.0\x86_64-w64-mingw32\bits
#include <bits/stdc++.h>

#include <atcoder/all>

#include <iostream>

using namespace std;
using namespace atcoder;

////////////////////////////////////////////////////////////
//////////////////   VISUALIZATION   ///////////////////////
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
//////////////////////   MATHS   ///////////////////////////
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
  for (long long i = 1; i <= MAXN; ++i)
  {
    fact[i] = fact[i - 1] * i % MOD;
  }
  inv_fact[MAXN] = mod_pow(fact[MAXN], MOD - 2, MOD); // Fermat's Little Theorem for inverse
  for (long long i = MAXN - 1; i >= 1; --i)
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
////////////////////   ALGORITHMS   ////////////////////////
////////////////////////////////////////////////////////////

/*
The function returns the index of the first element in v that is greater than or equal to x.
If no such element exists, it returns the index past the last element (i.e., the size of the vector).
 */
template <typename T>
T bs(const vector<T> &v, T x)
{
  return lower_bound(begin(v), end(v), x) - begin(v);
}

////////////////////////////////////////////////////////////
////////////////////   SOLUTION   //////////////////////////
////////////////////////////////////////////////////////////

void solve()
{
  int n, q;
  string s;
  cin >> n >> q >> s;

  int count1 = 0, count2 = 0, counts = 0;
  vector<int> ones(n + 1, 0);
  vector<int> twos(n + 1, 0);
  vector<int> slashes(n + 1, 0);
  vector<int> slashes_loc = {};

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
      count1++;
    else if (s[i] == '2')
      count2++;
    else
      counts++;

    if (s[i] == '/')
      slashes_loc.push_back(i);

    ones[i + 1] = count1;
    twos[i + 1] = count2;
    slashes[i + 1] = counts;
  }

  // print_vec(ones);
  // cout << endl;
  // print_vec(twos);
  // cout << endl;
  // print_vec(slashes);
  // cout << endl;
  // print_vec(slashes_loc);
  // cout << endl;

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    l--;

    auto f = [&](int len) -> bool
    {
      if (len == 0)
      {
        int num_of_slashes = slashes[r] - slashes[l];
        if (num_of_slashes)
          return true;
      }

      // check all '/' in range [l-1, r)
      // then check if there are >= len 1 and 2 around it
      int sl_loc = slashes_loc[(slashes_loc, l)]; // leave at least 1 space
      while (sl_loc < r)
      {
        // cout << "sl_loc: " << sl_loc << "\n";
        // num of 1s on left
        int num_of_ones = ones[sl_loc - l];

        // num of 2s on right
        int num_of_twos = twos[r] - twos[sl_loc + 1];

        if (num_of_ones >= len && num_of_twos >= len)
          return true;

        // update sl_loc
        // cout << "bs: " << bs(slashes_loc, sl_loc + 1) << "\n";
        int newloc = bs(slashes_loc, sl_loc + 1);
        if (newloc >= slashes_loc.size()){
          break;
        }
        sl_loc = slashes_loc[bs(slashes_loc, sl_loc + 1)];
      }

      return false;
    };

    // binary search for the right length
    int largest_yes = -1, smallest_no = n+1;

    // when largest_yes = 4, smallest_no = 5
    // we should stop, as the boundary is clear now
    // keep doing it may fall into infinite loop
    while (largest_yes + 1 < smallest_no) {
      int mid = (largest_yes + smallest_no) / 2;
      
      (f(mid) ? largest_yes : smallest_no) = mid;
    }

    cout << (largest_yes == -1 ? 0 : 1 + 2 * largest_yes) << "\n";
  }
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

int main()
{
  cin.tie(0);

  solve();
}