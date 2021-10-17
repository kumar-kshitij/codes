// Problem: Subarray Divisibility
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1662
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

ll rem(ll x, ll n) {
  if (x < 0) {
    x += (abs(x) + n - 1) / n * n;
  }
  return x % n;
}

void solve() {
  // code...
  ll n;
  cin >> n;
  vl a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  vl count(n, 0);
  count[0] = 1;
  ll res = 0, sum = 0;
  for (ll i = 0; i < n; i++) {
    sum += a[i];
    res += count[rem(sum, n)];
    count[rem(sum, n)]++;
  }
  cout << res << nl;
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
