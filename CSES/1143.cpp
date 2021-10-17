// Problem: Hotel Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1143
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

vl h, st;

void build(ll n, ll s, ll e) {
  if (s == e) {
    st[n] = s;
    return;
  }
  ll m = s + (e - s) / 2;
  build(2 * n, s, m);
  build(2 * n + 1, m + 1, e);
  st[n] = h[st[2 * n]] > h[st[2 * n + 1]] ? st[2 * n] : st[2 * n + 1];
}

void update(ll n, ll s, ll e, ll i, ll v) {
  if (s == e) {
    h[i] += v;
    st[n] = s;
    return;
  }
  ll m = s + (e - s) / 2;
  if (i <= m) {
    update(2 * n, s, m, i, v);
  } else {
    update(2 * n + 1, m + 1, e, i, v);
  }
  st[n] = h[st[2 * n]] > h[st[2 * n + 1]] ? st[2 * n] : st[2 * n + 1];
}

ll query(ll n, ll s, ll e, ll r) {
  if (r > h[st[n]]) {
    return 0;
  }
  if (s == e) {
    return st[n];
  }
  ll m = s + (e - s) / 2;
  ll l = query(2 * n, s, m, r);
  if (l != 0) {
    return l;
  }
  return query(2 * n + 1, m + 1, e, r);
}

void solve() {
  // code...
  ll n, m;
  cin >> n >> m;
  h.resize(n + 1, 0);
  vl r(m + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (ll i = 1; i <= m; i++) {
    cin >> r[i];
  }
  st.resize(4 * n);
  build(1, 1, n);
  for (ll i = 1; i <= m; i++) {
    ll res = query(1, 1, n, r[i]);
    update(1, 1, n, res, -r[i]);
    cout << res << " ";
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
