// Problem: Maximum Subarray Sum II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1644
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
#define inf 1e18

ll dx[] = {0, 1, 0, -1, 0};

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
  ll n, a, b;
  cin >> n >> a >> b;
  vl x(n);
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (ll i = 1; i < n; i++) {
    x[i] += x[i - 1];
  }
  multiset<ll> s;
  s.insert(0);
  bool flag = 0;
  ll res = -inf;
  res = max(res, x[a - 1]);
  for (ll i = a; i < n; i++) {
    if (i >= b && !flag) {
      s.erase(s.find(0));
      flag = 1;
    }
    if (i >= a) {
      s.insert(x[i - a]);
    }
    res = max(res, x[i] - *s.begin());
    if (i >= b) {
      s.erase(s.find(x[i - b]));
    }
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
