#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  long N;
  long long *l, *r;
  cin >> N;
  l = new long long[N];
  r = new long long[N];
  for (int i = 0; i < N; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l, l + N);
  sort(r, r + N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += l[i] > r[i] ? l[i] : r[i];
  }
  cout << ans + N << endl;

  return 0;
}
