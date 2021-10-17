// Problem: Static Range Minimum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1647
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
  ll maxJ = log2(n);
  vector<vl> lookup(n, vl(maxJ + 1));
  for (ll i = 0; i < n; i++) {
    cin >> lookup[i][0];
  }
  for (ll j = 1; j <= maxJ; j++) {
    for (ll i = 0; i < n - (1 << (j - 1)); i++) {
      lookup[i][j] = min(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
    }
  }
  while (q--) {
    ll a, b;
    cin >> a >> b;
    ll j = log2(b - a + 1);
    cout << min(lookup[a - 1][j], lookup[b - (1 << j)][j]) << nl;
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
