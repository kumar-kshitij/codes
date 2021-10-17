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
        ll edges[m][3];
        for (ll i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        ll x;
        vl dist(n + 1, 0), prev(n + 1, -1);
        for (ll i = 0; i < n; i++) {
            x = -1;
            for (ll j = 0; j < m; j++) {
                if (dist[edges[j][0]] != LLONG_MAX &&
                    dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2]) {
                    dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                    prev[edges[j][1]] = edges[j][0];
                    x = edges[j][1];
                }
            }
        }
        if (x == -1) {
            cout << "NO";
        } else {
            for (ll i = 0; i < n; i++) {
                x = prev[x];
            }
            vl cycle;
            for (ll i = x;; i = prev[i]) {
                cycle.pb(i);
                if (i == x && cycle.size() > 1) {
                    break;
                }
            }
            cout << "YES" << nl;
            for (ll i = cycle.size() - 1; i >= 0; i--) {
                cout << cycle[i] << " ";
            }
        }
    }
    return 0;
}
