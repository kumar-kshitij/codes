#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) { return x * y - x - 9; }
double g(double x, double y) { return y * y - x * x - 7; }
double fx(double x, double y) { return y - 1; }
double fy(double x, double y) { return x; }
double gx(double x, double y) { return -2 * x; }
double gy(double x, double y) { return 2 * y; }

int main() {
  double x, y, n;
  cin >> x >> y >> n;
  cout << setprecision(6) << fixed;
  for (int i = 0; i < n; i++) {
    double d = 1.0 / (fx(x, y) * gy(x, y) - fy(x, y) * gx(x, y));
    double x1 = x - d * (gy(x, y) * f(x, y) - fy(x, y) * g(x, y));
    double y1 = y - d * (-gx(x, y) * f(x, y) + fx(x, y) * g(x, y));
    x = x1;
    y = y1;
  }
  cout << x << " " << y << "\n";
  return 0;
}