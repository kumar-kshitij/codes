// Problem: Sliding Median
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1076
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

ll k;
multiset<ll> lo, hi;

void ins(ll v) {
  if (v <= *lo.rbegin()) {
    lo.insert(v);
    if (lo.size() > (k + 1) / 2) {
      hi.insert(*lo.rbegin());
      lo.erase(lo.find(*lo.rbegin()));
    }
  } else {
    hi.insert(v);
    if (hi.size() > k / 2) {
      lo.insert(*hi.begin());
      hi.erase(hi.find(*hi.begin()));
    }
  }
}

void ers(ll v) {
  if (hi.find(v) != hi.end()) {
    hi.erase(hi.find(v));
  } else {
    lo.erase(lo.find(v));
  }
  if (lo.empty()) {
    lo.insert(*hi.begin());
    hi.erase(hi.find(*hi.begin()));
  }
}

void solve() {
  // code...
  ll n;
  cin >> n >> k;
  vl x(n);
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
  }
  lo.insert(x[0]);
  for (ll i = 1; i < k; i++) {
    ins(x[i]);
  }
  cout << *lo.rbegin() << " ";
  for (ll i = 0, j = k; j < n; i++, j++) {
    if (k == 1) {
      ins(x[j]);
      ers(x[i]);
    } else {
      ers(x[i]);
      ins(x[j]);
    }
    cout << *lo.rbegin() << " ";
  }
  cout << nl;
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
