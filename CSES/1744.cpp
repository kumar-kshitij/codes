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

ll f(vector<vl> &dp, ll i, ll j) {
    if (i > j) {
        swap(i, j);
    }
    return dp[i][j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        vector<vl> dp(a + 1, vl(b + 1, 0));
        for (ll j = 1; j <= b; j++) {
            dp[1][j] = j;
        }
        for (ll i = 2; i <= a; i++) {
            for (ll j = i; j <= b; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = INT_MAX;
                    for (ll k = 1; k <= i; k++) {
                        dp[i][j] = min(
                            dp[i][j],
                            dp[k][k] + min(f(dp, i - k, k) + f(dp, i, j - k),
                                           f(dp, i - k, j) + f(dp, k, j - k)));
                    }
                }
            }
        }
        cout << dp[a][b] - 1;
    }
    return 0;
}
