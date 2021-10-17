// Problem: Range Update Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1651
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
  vl x(n + 1), BIT(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> x[i];
  }
  while (q--) {
    ll opt;
    cin >> opt;
    if (opt == 1) {
      ll a, b, u;
      cin >> a >> b >> u;
      for (ll j = a; j <= n; j += j & -j) {
        BIT[j] += u;
      }
      for (ll j = b + 1; j <= n; j += j & -j) {
        BIT[j] -= u;
      }
    } else {
      ll k;
      cin >> k;
      ll res = x[k];
      for (ll j = k; j > 0; j -= j & -j) {
        res += BIT[j];
      }
      cout << res << nl;
    }
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
