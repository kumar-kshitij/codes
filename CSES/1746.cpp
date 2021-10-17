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
        ll n, m;
        cin >> n >> m;
        ll x[n];
        ll dp[n][m + 1];
        memset(dp, 0, sizeof(dp));
        for (ll i = 0; i < n; i++) {
            cin >> x[i];
        }
        if (x[0] == 0) {
            for (ll j = 1; j <= m; j++) {
                dp[0][j] = 1;
            }
        } else {
            dp[0][x[0]] = 1;
        }
        for (ll i = 1; i < n; i++) {
            if (x[i] == 0) {
                for (ll j = 1; j <= m; j++) {
                    if (j > 1) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                    }
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                    if (j < m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
                    }
                }
            } else {
                if (x[i] > 1) {
                    dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % mod;
                }
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]]) % mod;
                if (x[i] < m) {
                    dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % mod;
                }
            }
        }
        ll res = 0;
        for (ll j = 1; j <= m; j++) {
            res = (res + dp[n - 1][j]) % mod;
        }
        cout << res;
    }
    return 0;
}
