#include <bits/stdc++.h>
using namespace std;

double f1(double t, double u, double v) { return u * v + t; }
double f2(double t, double u, double v) { return t * v + u; }

int main() {
  cout << fixed << setprecision(6);
  double t0, u0, v0, tn, h;
  cin >> t0 >> u0 >> v0 >> tn >> h;
  int n = round((tn - t0) / h);
  double up = u0 + h * f1(t0, u0, v0);
  double vp = v0 + h * f2(t0, u0, v0);
  cout << "Predicted : " << up << " " << vp << "\n";
  for (int i = 0; i < n; i++) {
    up = u0 + 0.5 * h * (f1(t0, u0, v0) + f1(t0 + h, up, vp));
    vp = v0 + 0.5 * h * (f2(t0, u0, v0) + f2(t0 + h, up, vp));
    cout << "Corrected : " << up << " " << vp << "\n";
  }
  return 0;
}
