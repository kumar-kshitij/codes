#include <bits/stdc++.h>
using namespace std;

double f(double x) { return sin(M_PI * x); }

double u[100][100];

int main() {
  double alpha = 1;
  double h = 1.0 / 4, l = 1.0 / 16;
  double lambda = alpha * l / (h * h);
  int m = 4, n = 16;
  int maxItr = 100;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) u[i][j] = f(i * h);
  }
  for (int j = 0; j <= n; j++) {
    u[0][j] = 0;
    u[m][j] = j * l;
  }
  for (int itr = 1; itr <= maxItr; itr++) {
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i < m; i++) {
        double c = u[i][j - 1] +
                   (lambda / 2) *
                       (u[i - 1][j - 1] - 2 * u[i][j - 1] + u[i + 1][j - 1]);
        u[i][j] =
            ((lambda / 2) * (u[i - 1][j] + u[i + 1][j]) + c) / (1 + lambda);
      }
    }
  }
  cout << fixed << setprecision(5) << u[2][2] << "\n";
  // cout << fixed << setprecision(3);
  // for (int i = 0; i <= m; i++) {
  //     for (int j = 0; j <= n; j++) cout << u[i][j] << "\t";
  //     cout << "\n";
  // }
  return 0;
}
