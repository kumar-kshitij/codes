#include <bits/stdc++.h>
using namespace std;

double f(double x) { return sin(M_PI * x); }

double u[100][100];

int main() {
  double alpha = 1;
  double h = 1.0 / 9, l = 1.0 / 27;
  double lambda = alpha * l / (h * h);
  int m = 9, n = 27;
  int maxItr = 100;
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) u[i][j] = f(i * h);
  }
  for (int j = 0; j <= n; j++) {
    u[0][j] = 0;
    u[m][j] = 0;
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
  cout << fixed << setprecision(5);
  for (int j = 1; j <= 2; j++) {
    cout << "Level " << j << ":\n";
    for (int i = 0; i <= m; i++) cout << u[i][j] << " ";
    cout << "\n";
  }
  return 0;
}

// OUTPUT
// Level 1:
// 0.00000 0.23722 0.44583 0.60067 0.68305 0.68305 0.60067 0.44583 0.23722
// 0.00000 Level 2: 0.00000 0.16454 0.30923 0.41662 0.47376 0.47376 0.41662
// 0.30923 0.16454 0.00000