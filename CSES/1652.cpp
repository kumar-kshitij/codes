// Problem: Forest Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1652
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define X first
#define Y second
#define pb emplace_back
#define nl "\n"
#define vl vector<ll>
#define mod 1000000007

ll dx[] = {0, 1, 0, -1, 0};

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }
ll power(ll a, ll b, ll m) {
  a %= m;
  ll r = 1;
  while (b > 0) {
    if (b & 1) r = r * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return r;
}

void solve() {
  // code...
  ll n, q;
  cin >> n >> q;
  vector<vl> pre(n + 1, vl(n + 1, 0));
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      if (ch == '*') {
        pre[i][j] = 1;
      }
      pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
    }
  }
  while (q--) {
    ll y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << pre[y2][x2] - pre[y2][x1 - 1] - pre[y1 - 1][x2] +
                pre[y1 - 1][x1 - 1]
         << nl;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
