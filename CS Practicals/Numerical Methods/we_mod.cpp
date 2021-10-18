#include <bits/stdc++.h>
using namespace std;

double f(double x) { return 0.5 * x * (1 - x); }

double u[100][100];

int main() {
  double alpha = 1;
  double h = 0.25, l = 0.2;
  double lambda = alpha * l * l / (h * h);
  cout << lambda << "\n";
  int m = 4, n = 10;
  for (int i = 0; i <= m; i++) {
    u[i][0] = f(i * h);
  }
  for (int j = 0; j <= n; j++) {
    u[0][j] = 0;
    u[m][j] = 0;
  }
  for (int i = 1; i < m; i++)
    u[i][1] =
        (lambda * (u[i - 1][0] + u[i + 1][0]) + 2 * (1 - lambda) * u[i][0]) / 2;
  for (int j = 2; j <= n; j++) {
    for (int i = 1; i < m; i++) {
      u[i][j] = -u[i][j - 2] + lambda * (u[i - 1][j - 1] + u[i + 1][j - 1]) +
                2 * (1 - lambda) * u[i][j - 1];
    }
  }
  // cout << fixed << setprecision(5) << u[1][1] << "\n";
  cout << fixed << setprecision(5);
  for (int j = 0; j <= 2; j++) {
    for (int i = 0; i <= m; i++) cout << u[i][j] << " ";
    cout << "\n";
  }
  return 0;
}