#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
  ll n;
  ld X;
  cin >> n >> X;
  ld x[n];
  ld y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }
  ld sum = 0;
  for (int i = 0; i < n; i++) {
    ld product = 1;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        product *= (X - x[j]) / (x[i] - x[j]);
      }
    }
    sum += product * y[i];
  }
  cout << sum << "\n";
  return 0;
}

// Input 1
// 4 1.25
// 0 1 2 3
// 1 2.25 3.75 4.25
// Output 1
// 2.65039

// Input 2
// 6 1998
// 1980 1985 1990 1995 2000 2005
// 440 510 525 571 500 600
// Output 2
// 541.579