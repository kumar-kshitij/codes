#include <bits/stdc++.h>
using namespace std;

double f1(double x) { return 1 / (x + 1); }
double f2(double x) { return exp(x * x); }
double f3(double x) { return sin(x) / x; }

double solveF1() {
  double lx, ux;
  int n;
  cin >> lx >> ux >> n;
  double res = 0;
  double h = (ux - lx) / n;
  for (int i = 0; i <= n; i++) {
    if (i == 0 || i == n)
      res += f1(lx + i * h);
    else if (i % 2 == 0)
      res += 2 * f1(lx + i * h);
    else
      res += 4 * f1(lx + i * h);
  }
  res *= (h / 3);
  cout << res << "\n\n";
}

double solveF2() {
  double lx, ux;
  int n;
  cin >> lx >> ux >> n;
  double res = 0;
  double h = (ux - lx) / n;
  for (int i = 0; i <= n; i++) {
    if (i == 0 || i == n)
      res += f2(lx + i * h);
    else if (i % 2 == 0)
      res += 2 * f2(lx + i * h);
    else
      res += 4 * f2(lx + i * h);
  }
  res *= (h / 3);
  cout << res << "\n\n";
}

double solveF3() {
  double lx, ux;
  int n;
  cin >> lx >> ux >> n;
  double res = 0;
  double h = (ux - lx) / n;
  for (int i = 0; i <= n; i++) {
    if (i == 0 || i == n)
      res += f3(lx + i * h);
    else if (i % 2 == 0)
      res += 2 * f3(lx + i * h);
    else
      res += 4 * f3(lx + i * h);
  }
  res *= (h / 3);
  cout << res << "\n\n";
}

int main() {
  cout << setprecision(6) << fixed;
  // solveF1();
  // solveF2();
  solveF3();
  return 0;
}

// INPUT
// 2 3 4
// OUTPUT
// 0.287683

// INPUT
// 0 1 10
// OUTPUT
// 1.462681

// INPUT
// 0 1.57 11
// OUTPUT
// 0.951633