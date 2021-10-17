// Problem: Nearest Smaller Values
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1645
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
  ll n;
  cin >> n;
  vl x(n);
  for (ll i = 0; i < n; i++) {
    cin >> x[i];
  }
  vl res(n, 0);
  stack<ll> st;
  for (ll i = n - 1; i >= 0; i--) {
    while (!st.empty() && x[st.top()] > x[i]) {
      res[st.top()] = i + 1;
      st.pop();
    }
    st.push(i);
  }
  for (ll i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << nl;
  return;
}

int main() {
  // auto start = chrono::steady_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  // auto end = chrono::steady_clock::now();
  // cout << nl << "Elapsed time : "
  //      << chrono::duration_cast<chrono::milliseconds>(end - start).count()
  //      << " ms" << nl;
  return 0;
}
