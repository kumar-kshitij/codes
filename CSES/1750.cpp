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
    ll n, q;
    cin >> n >> q;
    ll maxJ = ceil(log2(1e9));
    ll next[n + 1][maxJ + 1];
    for (ll i = 1; i <= n; i++) {
        cin >> next[i][0];
    }
    for (ll j = 1; j <= maxJ; j++) {
        for (ll i = 1; i <= n; i++) {
            next[i][j] = next[next[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        ll x, k;
        cin >> x >> k;
        ll j = 0;
        while (k > 0) {
            x = k & 1 ? next[x][j] : x;
            j++;
            k /= 2;
        }
        cout << x << nl;
    }
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
