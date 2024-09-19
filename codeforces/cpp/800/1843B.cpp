#include "bits/stdc++.h"
using namespace std;

///////////////////////////////////////////////////////////////////////
/////////////////////////////// Macros ////////////////////////////////
///////////////////////////////////////////////////////////////////////

#define printv(v)                      \
	{                                    \
		printf("[");                       \
		for (int i = 0; i < v.size(); ++i) \
		{                                  \
			cout << v[i] << ", ";            \
		}                                  \
		printf("]\n");                     \
	}
#define print2D(tb)              \
	{                              \
		for (auto &row : tb)         \
		{                            \
			printf("[");               \
			for (auto &column : row)   \
			{                          \
				cout << column << ",\t"; \
			}                          \
			printf("]\n");             \
		}                            \
	}
#define printm(m)                             \
	{                                           \
		for (auto const &[k, v] : m)              \
		{                                         \
			cout << "{" << k << ": " << v << "}\n"; \
		}                                         \
	}
#define loop(i, b, e) for (ll i = b; i < e; i++)
#define rloop(i, b, e) for (ll i = b; i > e; i--)
#define sz(a) (ll) a.size()

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<ll> vll;

///////////////////////////////////////////////////////////////////////
///////////////////////// Algorithms //////////////////////////////////
///////////////////////////////////////////////////////////////////////
const int pascal_size = 100;
ll Pascal[pascal_size + 1][pascal_size + 1] = {};

// This is mainly for combinatorics
void create_pascal()
{
	Pascal[0][0] = 1;
	for (int n = 1; n <= pascal_size; ++n)
	{
		Pascal[n][0] = Pascal[n][n] = 1;
		for (int k = 1; k < n; ++k)
			Pascal[n][k] = Pascal[n - 1][k - 1] + Pascal[n - 1][k];
	}
}

ull sum_to(ull n)
{
	return n * (n + 1) / 2;
}

template <class T>
inline int
sgn(T v)
{
	return (v > T(0)) - (v < T(0));
}

// Initialize the program to prepare everything for our algorithms
void initialize()
{
	create_pascal();
}

// Sorting
// std::sort(numbers.begin(), numbers.end(), std::greater{});

///////////////////////////////////////////////////////////////////////
///////////////////////// Declarations ////////////////////////////////
///////////////////////////////////////////////////////////////////////
ll m, n, k, t, p, q, x, y;
string s;

///////////////////////////////////////////////////////////////////////

void solve(int tc = 0)
{
	cin >> n;
	vll a(n);

	ll sum = 0;
	ll cnt = 0;
	bool flag = false;
	loop(i, 0, n)
	{
		cin >> a[i];
		sum += abs(a[i]);
		if (!flag)
		{
			if (a[i] < 0)
			{
				flag = true;
				cnt += 1;
			}
			else
				continue;
		}
		else
		{
			if (a[i] > 0)
			{
				flag = false;
			}
			else
				continue;
		}
	}

	printf("%lld %lld\n", sum, cnt);
}

int main()
{
	int tc = 1;
	cin >> tc;
	// initialize();
	for (int t = 0; t < tc; t++)
	{
		solve(t);
	}
}