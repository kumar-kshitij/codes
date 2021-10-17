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

ll mod = 1000000007;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n;
        cin >> n;
        vl dp(n + 1, 0);
        dp[0] = 1;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= min(i, 6); j++) {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
        cout << dp[n];
    }
    return 0;
}
