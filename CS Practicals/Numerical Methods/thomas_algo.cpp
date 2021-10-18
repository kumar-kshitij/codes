#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  double a[n], b[n], c[n], d[n];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  c[n - 1] = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  c[0] /= b[0];
  d[0] /= b[0];
  for (int i = 1; i < n - 1; i++) {
    c[i] /= b[i] - a[i] * c[i - 1];
    d[i] = (d[i] - a[i] * d[i - 1]) / (b[i] - a[i] * c[i - 1]);
  }
  d[n - 1] =
      (d[n - 1] - a[n - 1] * d[n - 2]) / (b[n - 1] - a[n - 1] * c[n - 2]);
  for (int i = n - 1; i-- > 0;) {
    d[i] -= c[i] * d[i + 1];
  }
  for (int i = 0; i < n; i++) {
    cout << d[i] << " ";
  }
  return 0;
}
