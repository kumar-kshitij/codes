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

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }
ll power(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n;
        cin >> n;
        ll x[n], dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (ll i = 0; i < n; i++) {
            cin >> x[i];
            dp[i][i] = x[i];
        }
        for (ll i = 1; i < n; i++) {
            x[i] += x[i - 1];
        }
        for (ll l = 2; l <= n; l++) {
            for (ll i = 0; i <= n - l; i++) {
                ll j = i + l - 1;
                dp[i][j] = x[j] - (i > 0 ? x[i - 1] : 0) -
                           min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[0][n - 1];
    }
    return 0;
}
