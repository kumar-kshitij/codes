#include <bits/stdc++.h>
using namespace std;

double f1(double t, double u, double v) { return u * v + t; }
double f2(double t, double u, double v) { return t * v + u; }

int main() {
  cout << fixed << setprecision(6);
  double h, t0, u0, u1, u2, u3, v0, v1, v2, v3;
  cin >> h >> t0 >> u0 >> v0 >> u1 >> v1 >> u2 >> v2 >> u3 >> v3;
  double un =
      u3 + h / 24 *
               (55 * f1(t0 + 3 * h, u3, v3) - 59 * f1(t0 + 2 * h, u2, v2) +
                37 * f1(t0 + h, u1, v1) - 9 * f1(t0, u0, v0));
  double vn =
      v3 + h / 24 *
               (55 * f2(t0 + 3 * h, u3, v3) - 59 * f2(t0 + 2 * h, u2, v2) +
                37 * f2(t0 + h, u1, v1) - 9 * f2(t0, u0, v0));
  cout << "Predicted : " << un << " " << vn << "\n";
  un = u3 + h / 24 *
                (9 * f1(t0 + 3 * h, u3, v3) + 19 * f1(t0 + 2 * h, u2, v2) -
                 5 * f1(t0 + h, u1, v1) + f1(t0, u0, v0));
  vn = v3 + h / 24 *
                (9 * f2(t0 + 3 * h, u3, v3) + 19 * f2(t0 + 2 * h, u2, v2) -
                 5 * f2(t0 + h, u1, v1) + f2(t0, u0, v0));
  cout << "Corrected : " << un << " " << vn << "\n";
  return 0;
}
