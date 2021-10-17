// Problem: Dynamic Range Minimum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1649
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

void build(vl &st, vl &x, ll n, ll s, ll e) {
  if (s == e) {
    st[n] = x[s];
    return;
  }
  ll m = s + (e - s) / 2;
  build(st, x, 2 * n, s, m);
  build(st, x, 2 * n + 1, m + 1, e);
  st[n] = min(st[2 * n], st[2 * n + 1]);
}

void update(vl &st, vl &x, ll n, ll s, ll e, ll i, ll v) {
  if (s == e) {
    st[n] = x[i] = v;
    return;
  }
  ll m = s + (e - s) / 2;
  if (s <= i && i <= m) {
    update(st, x, 2 * n, s, m, i, v);
  } else {
    update(st, x, 2 * n + 1, m + 1, e, i, v);
  }
  st[n] = min(st[2 * n], st[2 * n + 1]);
}

ll query(vl &st, ll n, ll s, ll e, ll l, ll r) {
  if (s > r || e < l) {
    return INT_MAX;
  }
  if (s >= l && e <= r) {
    return st[n];
  }
  ll m = s + (e - s) / 2;
  return min(query(st, 2 * n, s, m, l, r),
             query(st, 2 * n + 1, m + 1, e, l, r));
}

void solve() {
  // code...
  ll n, q;
  cin >> n >> q;
  vl x(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> x[i];
  }
  vl st(4 * n);
  build(st, x, 1, 1, n);
  while (q--) {
    ll opt;
    cin >> opt;
    if (opt == 1) {
      ll k, u;
      cin >> k >> u;
      update(st, x, 1, 1, n, k, u);
    } else {
      ll a, b;
      cin >> a >> b;
      cout << query(st, 1, 1, n, a, b) << nl;
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
