#include <bits/stdc++.h>
using namespace std;

double f1(double x) { return exp(-x); }
double f2(double x) { return x * x; }
double f3(double x) { return sin(M_PI * x); }

double u[100][100];

int main() {
  double alpha, lambda, x0, xn, t0, tm, h, l;
  alpha = 1;
  h = 1, l = 1.0 / 36;
  x0 = 0, xn = 8;
  t0 = 0;
  lambda = alpha * l / (h * h);
  int n = 8;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 10; j++) u[i][j] = f1(x0 + i * h);
  }
  for (int j = 0; j < 10; j++) {
    u[0][j] = 0;
    u[n][j] = 0;
  }
  for (int itr = 1; itr <= 10; itr++) {
    for (int j = 1; j <= 10; j++) {
      for (int i = 1; i < n; i++) {
        double c = u[i][j - 1] +
                   (lambda / 2) *
                       (u[i - 1][j - 1] - 2 * u[i][j - 1] + u[i + 1][j - 1]);
        u[i][j] = (lambda / (2 * (1 + lambda))) * (u[i - 1][j] + u[i + 1][j]) +
                  c / (1 + lambda);
      }
    }
  }
  cout << fixed << setprecision(2);
  cout << "QUESTION 1:\n";
  for (int j = 3; j >= 0; j--) {
    for (int i = 0; i <= n; i++) cout << u[i][j] << " ";
    cout << "\n";
  }
  cout << "\n";

  h = 1.0 / 3, l = 1.0 / 36;
  x0 = 0, xn = 1;
  t0 = 0;
  lambda = alpha * l / (h * h);
  n = 3;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= 10; j++) u[i][j] = f3(x0 + i * h);
  }
  for (int j = 0; j < 10; j++) {
    u[0][j] = 0;
    u[n][j] = 0;
  }
  for (int itr = 1; itr <= 10; itr++) {
    for (int j = 1; j <= 10; j++) {
      for (int i = 1; i < n; i++) {
        double c = u[i][j - 1] +
                   (lambda / 2) *
                       (u[i - 1][j - 1] - 2 * u[i][j - 1] + u[i + 1][j - 1]);
        u[i][j] = (lambda / (2 * (1 + lambda))) * (u[i - 1][j] + u[i + 1][j]) +
                  c / (1 + lambda);
      }
    }
  }
  cout << "QUESTION 3:\n";
  for (int j = 10; j >= 0; j--) {
    for (int i = 0; i <= n; i++) cout << u[i][j] << " ";
    cout << "\n";
  };
  return 0;
}

// QUESTION 1:
// 0.00 0.32 0.14 0.05 0.02 0.01 0.00 0.00 0.00
// 0.00 0.34 0.14 0.05 0.02 0.01 0.00 0.00 0.00
// 0.00 0.35 0.14 0.05 0.02 0.01 0.00 0.00 0.00
// 0.00 0.37 0.14 0.05 0.02 0.01 0.00 0.00 0.00

// QUESTION 3:
// 0.00 0.07 0.07 0.00
// 0.00 0.09 0.09 0.00
// 0.00 0.12 0.12 0.00
// 0.00 0.15 0.15 0.00
// 0.00 0.19 0.19 0.00
// 0.00 0.25 0.25 0.00
// 0.00 0.32 0.32 0.00
// 0.00 0.41 0.41 0.00
// 0.00 0.52 0.52 0.00
// 0.00 0.67 0.67 0.00
// 0.00 0.87 0.87 0.00