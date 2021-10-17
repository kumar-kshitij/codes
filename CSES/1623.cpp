#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define X first
#define Y second
#define pb push_back
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

void dfs(vl &p, ll &tot, ll &res, ll n, ll sum) {
    if (n == -1) {
        res = min(res, llabs(tot - 2 * sum));
        return;
    }
    dfs(p, tot, res, n - 1, sum);
    dfs(p, tot, res, n - 1, sum + p[n]);
}

void solve() {
    // code...
    ll n;
    cin >> n;
    vl p(n);
    ll tot = 0;
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
        tot += p[i];
    }
    ll res = tot;
    dfs(p, tot, res, n - 1, 0);
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
