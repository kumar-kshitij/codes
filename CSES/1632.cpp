// Problem: Movie Festival II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1632
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
  ll n, k;
  cin >> n >> k;
  vector<pll> t(n);
  for (ll i = 0; i < n; i++) {
    cin >> t[i].X >> t[i].Y;
  }
  sort(t.begin(), t.end(), [](pll a, pll b) { return a.Y < b.Y; });
  multiset<ll> s;
  for (ll i = 0; i < k; i++) {
    s.insert(0);
  }
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    if (!s.empty() && *s.begin() <= t[i].X) {
      res++;
      s.erase(prev(s.upper_bound(t[i].X)));
      s.insert(t[i].Y);
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
