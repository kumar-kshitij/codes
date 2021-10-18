#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ni;
  cin >> n >> ni;
  // double e;
  // cin >> e;
  vector<vector<double>> A(n, vector<double>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  vector<double> X(n);
  for (int i = 0; i < n; i++) {
    cin >> X[i];
  }
  double lambda_old = 1;
  while (1) {
    vector<double> X_new(n);
    double lambda_new = INT_MIN;
    for (int i = 0; i < n; i++) {
      X_new[i] = 0;
      for (int j = 0; j < n; j++) {
        X_new[i] += A[i][j] * X[j];
      }
      lambda_new = max(lambda_new, X_new[i]);
    }
    for (int i = 0; i < n; i++) {
      X_new[i] /= lambda_new;
    }
    if (--ni == 0 /* || fabs(lambda_new - lambda_old) < e*/) {
      cout << fixed << setprecision(6) << lambda_new << "\n";
      for (int i = 0; i < n; i++) {
        cout << X_new[i] << " ";
      }
      break;
    }
    X = X_new;
    lambda_old = lambda_new;
  }
  return 0;
}

// INPUT
// 2 10
// 4 -5
// 2 3
// 1 1
// OUTPUT
// 4.051778
// -0.714857 1.000000

// INPUT
// 2 10
// 1 -5
// -3 -1
// 1 1
// OUTPUT
// -4.000000
// 1.000000 1.000000

// INPUT
// 3 10
// 2 -1 0
// -1 2 -1
// 0 -1 2
// 1 1 1
// OUTPUT
// 3.414211
// 1.000000 -1.414213 1.000000