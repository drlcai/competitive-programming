#include <atcoder/all>

#include <iostream>

using namespace std;
using namespace atcoder;

void solve()
{
  int N, Q;
  cin >> N >> Q;

  dsu d(N);

  /*
  While Q-- : memorize this for dealing with all stuff.
  */
  while (Q--)
  {
    int q, u, v;
    cin >> q >> u >> v;

    if (!q)
      d.merge(u, v);
    else
      cout << d.same(u, v) << "\n";
  }
}

int main()
{
  cin.tie(0);

  solve();
}