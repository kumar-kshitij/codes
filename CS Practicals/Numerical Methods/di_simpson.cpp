#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) { return x * x / (1 + y * y); }

// dydx
double solve(double h, double k, double lx, double ux, double ly, double uy) {
  int nx, ny;

  // z stores the table
  // ax[] stores the integral wrt y
  // for all x points considered
  double z[100][100], ax[100], res;

  // Calculating the numner of points
  // in x and y integral
  nx = (ux - lx) / h + 1;
  ny = (uy - ly) / k + 1;

  // Calculating the values of the table
  for (int i = 0; i < nx; ++i) {
    for (int j = 0; j < ny; ++j) {
      z[i][j] = f(lx + i * h, ly + j * k);
    }
  }

  // Calculating the integral value
  // wrt y at each point for x
  for (int i = 0; i < nx; ++i) {
    ax[i] = 0;
    for (int j = 0; j < ny; ++j) {
      if (j == 0 || j == ny - 1) ax[i] += z[i][j];
      // else if (j % 2 == 0)
      //     ax[i] += 2 * z[i][j];
      else
        ax[i] += 4 * z[i][j];
    }
    ax[i] *= (k / 3);
  }

  res = 0;

  // Calculating the final integral value
  // using the integral obtained in the above step
  for (int i = 0; i < nx; ++i) {
    if (i == 0 || i == nx - 1) res += ax[i];
    // else if (i % 2 == 0)
    //     res += 2 * ax[i];
    else
      res += 4 * ax[i];
  }
  res *= (h / 3);

  return res;
}

int main() {
  // lx and ux are upper and lower limit of x integral
  // ly and uy are upper and lower limit of y integral
  // h is the step size for integration wrt x
  // k is the step size for integration wrt y
  double h, k, lx, ux, ly, uy;
  cin >> h >> k >> lx >> ux >> ly >> uy;
  cout << setprecision(6) << fixed << solve(h, k, lx, ux, ly, uy);
  return 0;
}
