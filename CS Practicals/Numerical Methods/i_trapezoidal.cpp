#include <bits/stdc++.h>
using namespace std;

double f1(double x) { return 1 / (16 + x * x); }
double f2(double x) { return (300 * x) / (1 + exp(x)); }
double f3(double x) { return sqrt(x); }

double solveF1() {
  double lx, ux;
  int n;
  cin >> lx >> ux >> n;
  double res = 0;
  double h = (ux - lx) / n;
  for (int i = 0; i <= n; i++) {
    cout << lx + i * h << " ";
    if (i == 0 || i == n)
      res += f1(lx + i * h);
    else
      res += 2 * f1(lx + i * h);
  }
  res *= (h / 2);
  cout << "\n" << res << "\n\n";
}

double solveF2() {
  double lx, ux;
  int n;
  cin >> lx >> ux >> n;
  double res = 0;
  double h = (ux - lx) / n;
  for (int i = 0; i <= n; i++) {
    cout << lx + i * h << " ";
    if (i == 0 || i == n)
      res += f2(lx + i * h);
    else
      res += 2 * f2(lx + i * h);
  }
  res *= (h / 2);
  cout << "\n" << res << "\n\n";
}

double solveF3() {
  double lx, ux;
  int n;
  cin >> lx >> ux >> n;
  double res = 0;
  double h = (ux - lx) / n;
  for (int i = 0; i <= n; i++) {
    cout << lx + i * h << " ";
    if (i == 0 || i == n)
      res += f3(lx + i * h);
    else
      res += 2 * f3(lx + i * h);
  }
  res *= (h / 2);
  cout << "\n" << res << "\n\n";
}

int main() {
  cout << setprecision(6) << fixed;
  solveF1();
  solveF2();
  solveF3();
  return 0;
}

// INPUT
// 0 2 6
// OUTPUT
// 0.000000 0.333333 0.666667 1.000000 1.333333 1.666667 2.000000
// 0.115819

// INPUT
// 0 10 20
// OUTPUT
// 0.000000
// 0.500000 1.000000 1.500000 2.000000 2.500000 3.000000 3.500000 4.000000 4.500000
// 5.000000 5.500000 6.000000 6.500000 7.000000 7.500000 8.000000 8.500000 9.000000
// 9.500000 10.000000 243.462748

// INPUT
// 0 4 4
// OUTPUT
// 0.000000 1.000000 2.000000 3.000000 4.000000
// 5.146264