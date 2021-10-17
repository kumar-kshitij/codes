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
        ll n, q;
        cin >> n >> q;
        ll maxJ = ceil(log2(n));
        ll up[n + 1][maxJ + 1];
        for (ll i = 2; i <= n; i++) {
            cin >> up[i][0];
        }
        for (ll j = 0; j <= maxJ; j++) {
            up[1][j] = -1;
        }
        for (ll j = 1; j <= maxJ; j++) {
            for (ll i = 2; i <= n; i++) {
                up[i][j] = (up[i][j - 1] != -1 ? up[up[i][j - 1]][j - 1] : -1);
            }
        }
        while (q--) {
            ll x, k;
            cin >> x >> k;
            ll j = 0;
            while (x != -1 && k > 0) {
                x = k & 1 ? up[x][j] : x;
                j++;
                k /= 2;
            }
            cout << x << nl;
        }
    }
    return 0;
}
