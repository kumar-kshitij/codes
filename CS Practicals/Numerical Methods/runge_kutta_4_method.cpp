#include <bits/stdc++.h>
using namespace std;

double f1(double x, double y) { return x * x + y * y; }
double f2(double x, double y) { return x - y * y; }
double f3(double x, double y) { return sqrt(x + y); }

double solveF1() {
  double x0, y0, xn, h;
  cin >> x0 >> y0 >> xn >> h;
  int n = round((xn - x0) / h) + 1;
  for (int i = 0; i < n; i++) {
    double k1 = h * f1(x0, y0);
    double k2 = h * f1(x0 + 0.5 * h, y0 + 0.5 * k1);
    double k3 = h * f1(x0 + 0.5 * h, y0 + 0.5 * k2);
    double k4 = h * f1(x0 + h, y0 + k3);
    cout << x0 << " " << y0 << "\n";
    y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    x0 += h;
  }
  cout << "\n";
}

double solveF2() {
  double x0, y0, xn, h;
  cin >> x0 >> y0 >> xn >> h;
  int n = round((xn - x0) / h) + 1;
  for (int i = 0; i < n; i++) {
    double k1 = h * f2(x0, y0);
    double k2 = h * f2(x0 + 0.5 * h, y0 + 0.5 * k1);
    double k3 = h * f2(x0 + 0.5 * h, y0 + 0.5 * k2);
    double k4 = h * f2(x0 + h, y0 + k3);
    cout << x0 << " " << y0 << "\n";
    y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    x0 += h;
  }
  cout << "\n";
}

double solveF3() {
  double x0, y0, xn, h;
  cin >> x0 >> y0 >> xn >> h;
  int n = round((xn - x0) / h) + 1;
  for (int i = 0; i < n; i++) {
    double k1 = h * f3(x0, y0);
    double k2 = h * f3(x0 + 0.5 * h, y0 + 0.5 * k1);
    double k3 = h * f3(x0 + 0.5 * h, y0 + 0.5 * k2);
    double k4 = h * f3(x0 + h, y0 + k3);
    cout << x0 << " " << y0 << "\n";
    y0 += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
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
// 1 2.3 1.2 0.025
// OUTPUT
// 1.000000 2.300000
// 1.025000 2.467537
// 1.050000 2.658474
// 1.075000 2.878012
// 1.100000 3.133049
// 1.125000 3.432939
// 1.150000 3.790693
// 1.175000 4.224964
// 1.200000 4.763486

// INPUT
// 0 1 0.1 0.025
// OUTPUT
// 0.000000 1.000000
// 0.025000 0.975917
// 0.050000 0.953592
// 0.075000 0.932916
// 0.100000 0.913794

// INPUT
// 0.4 0.41 0.8 0.025
// OUTPUT
// 0.400000 0.410000
// 0.425000 0.432828
// 0.450000 0.456306
// 0.475000 0.480425
// 0.500000 0.505177
// 0.525000 0.530552
// 0.550000 0.556544
// 0.575000 0.583146
// 0.600000 0.610351
// 0.625000 0.638152
// 0.650000 0.666544
// 0.675000 0.695520
// 0.700000 0.725076
// 0.725000 0.755207
// 0.750000 0.785907
// 0.775000 0.817171
// 0.800000 0.848996