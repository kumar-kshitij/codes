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
        int n, x;
        cin >> n >> x;
        vl h(n), s(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<vector<int>> dp(n, vector<int>(x + 1, 0));
        if (h[0] <= x) {
            dp[0][h[0]] = s[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= x; j++) {
                dp[i][j] = max(dp[i - 1][j],
                               j >= h[i] ? s[i] + dp[i - 1][j - h[i]] : 0);
            }
        }
        int res = 0;
        for (int j = 0; j <= x; j++) {
            res = max(res, dp[n - 1][j]);
        }
        cout << res;
    }
    return 0;
}
