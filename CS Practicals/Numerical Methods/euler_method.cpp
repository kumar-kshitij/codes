#include <bits/stdc++.h>
using namespace std;

double f1(double x, double y) { return 6 - 2 * (y / x); }
double f2(double x, double y) { return y * log(y / x); }
double f3(double x, double y) { return (y - x) / (y + x); }

double solveF1() {
  double x0, y0, h, xn;
  cin >> x0 >> y0 >> h >> xn;
  int n = round((xn - x0) / h) + 1;
  for (int i = 0; i < n; i++) {
    double y = y0 + h * f1(x0, y0);
    cout << x0 << " " << y0 << "\n";
    y0 = y;
    x0 += h;
  }
  cout << "\n";
}

double solveF2() {
  double x0, y0, h, xn;
  cin >> x0 >> y0 >> h >> xn;
  int n = round((xn - x0) / h) + 1;
  for (int i = 0; i < n; i++) {
    double y = y0 + h * f2(x0, y0);
    cout << x0 << " " << y0 << "\n";
    y0 = y;
    x0 += h;
  }
  cout << "\n";
}

double solveF3() {
  double x0, y0, h, xn;
  cin >> x0 >> y0 >> h >> xn;
  int n = round((xn - x0) / h) + 1;
  for (int i = 0; i < n; i++) {
    double y = y0 + h * f3(x0, y0);
    cout << x0 << " " << y0 << "\n";
    y0 = y;
    x0 += h;
  }
  cout << "\n";
}

int main() {
  cout << fixed << setprecision(6);
  solveF1();
  solveF2();
  solveF3();
  return 0;
}

// INPUT
// 3 1 0.1 3.5
// OUTPUT
// 3.000000 1.000000
// 3.100000 1.533333
// 3.200000 2.034409
// 3.300000 2.507258
// 3.400000 2.955303
// 3.500000 3.381462

// INPUT
// 2 2.718 0.1 2.5
// OUTPUT
// 2.000000 2.718000
// 2.100000 2.801374
// 2.200000 2.882102
// 2.300000 2.959937
// 2.400000 3.034604
// 2.500000 3.105800

// INPUT
// 0 1 0.1 0.1
// OUTPUT
// 0.000000 1.000000
// 0.100000 1.100000