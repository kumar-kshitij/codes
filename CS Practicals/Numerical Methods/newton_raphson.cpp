#include <bits/stdc++.h>
using namespace std;

// #define f(x) x* x* x + 5 * x - 3
// #define g(x) 3 * x* x + 5

// #define f(x) x - cos(x)
// #define g(x) 1 + sin(x)

#define f(x) 3 * x - cos(x) - 1
#define g(x) 3 + sin(x)

int main() {
  double x, e, n, d;
  cin >> x >> e >> n >> d;
  cout << setprecision(6) << fixed;
  for (int i = 0; i < n; i++) {
    double f = f(x);
    double f1 = g(x);
    if (fabs(f1) < d) {
      cout << "too small slope\n";
      return 0;
    }
    double x1 = x - f / f1;
    if (fabs((x1 - x) / x1) < e) {
      cout << x1;
      return 0;
    }
    x = x1;
  }
  cout << "does not converge due to oscillation\n";
  return 0;
}