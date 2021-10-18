#include <bits/stdc++.h>
using namespace std;

#define f(x) x - sin(x)
#define g(x) 1 - cos(x)

int main() {
  double x = 1, e = 0.0001, maxItr = 100;
  cout << setprecision(6) << fixed;
  for (int itr = 0; itr < maxItr; itr++) {
    double f = f(x);
    double f1 = g(x);
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

// OUTPUT
// 0.000000