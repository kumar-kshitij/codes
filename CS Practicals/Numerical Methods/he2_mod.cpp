#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) { return sin(M_PI * x) * sin(M_PI * y); }

double u[50][50][50];

int main() {
  double alpha = 1;
  double h = 1.0 / 3, l = 1.0 / 72;
  double lambda = alpha * l / (h * h);
  int m = 3, n = 10;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= m; j++) {
      u[i][j][0] = f(i * h, j * h);
    }
  }
  for (int k = 0; k <= n; k++) {
    for (int i = 0; i <= m; i++) {
      u[i][0][k] = 0;
      u[i][n][k] = 0;
    }
    for (int j = 0; j <= m; j++) {
      u[0][j][k] = 0;
      u[m][j][k] = 0;
    }
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < m; j++) {
        u[i][j][k] = (1 - 4 * lambda) * u[i][j][k - 1] +
                     lambda * (u[i + 1][j][k - 1] + u[i - 1][j][k - 1] +
                               u[i][j + 1][k - 1] + u[i][j - 1][k - 1]);
      }
    }
  }
  cout << fixed << setprecision(5) << u[2][1][2] << "\n";
  return 0;
}
