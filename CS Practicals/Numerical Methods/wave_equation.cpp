#include <bits/stdc++.h>
using namespace std;

double f1(double x) { return 2 - x / (2 * M_PI); }
double f2(double x) { return x * x * (5 - x); }

double u[100][100];

void solveF1() {
  double alpha, lambda, x0, xn, t0, tm, h, l, c;
  cin >> c >> h >> l >> x0 >> xn;
  t0 = 0;
  alpha = c * l * l / (h * h);
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    u[i][0] = f1(x0 + i * h);
  }
  for (int j = 0; j < 10; j++) {
    u[0][j] = 0;
    u[n][j] = 0;
  }
  for (int i = 1; i < n; i++)
    u[i][1] =
        ((alpha * (u[i - 1][0] + u[i + 1][0]) + 2 * (1 - alpha) * u[i][0])) / 2;
  for (int j = 2; j <= 10; j++) {
    for (int i = 1; i < n; i++) {
      u[i][j] = -u[i][j - 2] + alpha * (u[i - 1][j - 1] + u[i + 1][j - 1]) +
                2 * (1 - alpha) * u[i][j - 1];
    }
  }
  cout << fixed << setprecision(2);
  for (int j = 10; j >= 0; j--) {
    for (int i = 0; i <= n; i++) cout << u[i][j] << " ";
    cout << "\n";
  }
}

void solveF2() {
  double alpha, lambda, x0, xn, t0, tm, h, l, c;
  cin >> c >> h >> l >> x0 >> xn;
  t0 = 0;
  alpha = c * l * l / (h * h);
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    u[i][0] = f2(x0 + i * h);
  }
  for (int j = 0; j < 10; j++) {
    u[0][j] = 0;
    u[n][j] = 0;
  }
  for (int i = 1; i < n; i++)
    u[i][1] =
        ((alpha * (u[i - 1][0] + u[i + 1][0]) + 2 * (1 - alpha) * u[i][0])) / 2;
  for (int j = 2; j <= 10; j++) {
    for (int i = 1; i < n; i++) {
      u[i][j] = -u[i][j - 2] + alpha * (u[i - 1][j - 1] + u[i + 1][j - 1]) +
                2 * (1 - alpha) * u[i][j - 1];
    }
  }
  cout << fixed << setprecision(2);
  for (int j = 10; j >= 0; j--) {
    for (int i = 0; i <= n; i++) cout << u[i][j] << " ";
    cout << "\n";
  }
}

int main() {
  solveF1();
  solveF2();
  return 0;
}