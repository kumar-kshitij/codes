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
    ll n, x;
    cin >> n >> x;
    vl w(n);
    for (ll i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<pll> dp(1 << n);
    dp[0] = {1, 0};
    for (ll s = 1; s < (1 << n); s++) {
        dp[s] = {n + 1, 0};
        for (ll p = 0; p < n; p++) {
            if (s & (1 << p)) {
                pll prev = dp[s ^ (1 << p)];
                if (prev.Y + w[p] <= x) {
                    prev.Y += w[p];
                } else {
                    prev.X++;
                    prev.Y = w[p];
                }
                dp[s] = min(dp[s], prev);
            }
        }
    }
    cout << dp[(1 << n) - 1].X << nl;
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
