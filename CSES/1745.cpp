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
        ll x[n + 1];
        ll maxSum = 0;
        for (ll i = 1; i <= n; i++) {
            cin >> x[i];
            maxSum += x[i];
        }
        bool dp[n + 1][maxSum + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j <= maxSum; j++) {
                dp[i][j] =
                    dp[i - 1][j] || (j >= x[i] ? dp[i - 1][j - x[i]] : 0);
            }
        }
        ll res = 0;
        for (ll j = 1; j <= maxSum; j++) {
            res += dp[n][j];
        }
        cout << res << nl;
        for (ll j = 1; j <= maxSum; j++) {
            if (dp[n][j]) {
                cout << j << " ";
            }
        }
    }
    return 0;
}
