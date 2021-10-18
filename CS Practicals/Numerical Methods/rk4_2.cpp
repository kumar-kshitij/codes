#include <bits/stdc++.h>
using namespace std;

double f1(double t, double u, double v) { return v; }
double f2(double t, double u, double v) { return cos(t) - 4 * u; }

int main() {
  cout << fixed << setprecision(6);
  double t0, u0, v0, tn, h;
  cin >> t0 >> u0 >> v0 >> tn >> h;
  int n = round((tn - t0) / h);
  for (int i = 0; i < n; i++) {
    double k11 = h * f1(t0, u0, v0);
    double k21 = h * f2(t0, u0, v0);
    double k12 = h * f1(t0 + 0.5 * h, u0 + 0.5 * k11, v0 + 0.5 * k21);
    double k22 = h * f2(t0 + 0.5 * h, u0 + 0.5 * k11, v0 + 0.5 * k21);
    double k13 = h * f1(t0 + 0.5 * h, u0 + 0.5 * k12, v0 + 0.5 * k22);
    double k23 = h * f2(t0 + 0.5 * h, u0 + 0.5 * k12, v0 + 0.5 * k22);
    double k14 = h * f1(t0 + h, u0 + k13, v0 + k23);
    double k24 = h * f2(t0 + h, u0 + k13, v0 + k23);
    u0 += (k11 + 2 * k12 + 2 * k13 + k14) / 6;
    v0 += (k21 + 2 * k22 + 2 * k23 + k24) / 6;
    t0 += h;
    cout << "k11 = " << k11 << "\n";
    cout << "k21 = " << k21 << "\n";
    cout << "k12 = " << k12 << "\n";
    cout << "k22 = " << k22 << "\n";
    cout << "k13 = " << k13 << "\n";
    cout << "k23 = " << k23 << "\n";
    cout << "k14 = " << k14 << "\n";
    cout << "k24 = " << k24 << "\n";
    cout << u0 << " " << v0 << "\n";
  }
  return 0;
}
