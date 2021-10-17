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

ll n, m;

void genMasks(ll &prevMask, vl &masks, ll nm, ll i) {
    if (i >= n) {
        masks.pb(nm);
        return;
    }
    if (!(prevMask & (1 << i))) {
        genMasks(prevMask, masks, nm + (1 << i), i + 1);
        if (i < n - 1 && !(prevMask & (1 << i + 1))) {
            genMasks(prevMask, masks, nm, i + 2);
        }
    } else {
        genMasks(prevMask, masks, nm, i + 1);
    }
};

ll rec(vector<vl> &dp, ll j, ll prevMask) {
    if (j == m) {
        return (prevMask == 0);
    }
    if (dp[j][prevMask] != -1) {
        return dp[j][prevMask];
    }
    dp[j][prevMask] = 0;
    vl masks;
    genMasks(prevMask, masks, 0, 0);
    for (ll i = 0; i < masks.size(); i++) {
        dp[j][prevMask] = (dp[j][prevMask] + rec(dp, j + 1, masks[i])) % mod;
    }
    return dp[j][prevMask];
}

void solve() {
    // code...
    cin >> n >> m;
    vector<vl> dp(m, vl(1 << n, -1));
    cout << rec(dp, 0, 0) << nl;
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
