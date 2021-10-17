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
        ll n, m, q;
        cin >> n >> m >> q;
        ll dist[n + 1][n + 1];
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = LLONG_MAX;
                }
            }
        }
        while (m--) {
            ll a, b, c;
            cin >> a >> b >> c;
            dist[a][b] = dist[b][a] = min(dist[a][b], c);
        }
        for (ll k = 1; k <= n; k++) {
            for (ll i = 1; i <= n; i++) {
                for (ll j = 1; j <= n; j++) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX &&
                        dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        while (q--) {
            ll a, b;
            cin >> a >> b;
            cout << (dist[a][b] == LLONG_MAX ? -1 : dist[a][b]) << nl;
        }
    }
    return 0;
}
