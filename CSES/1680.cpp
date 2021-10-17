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

void dfs(vl graph[], vl &hgt, vl &nxt, ll u) {
    ll maxH = 0;
    for (ll v : graph[u]) {
        if (hgt[v] == -1) {
            dfs(graph, hgt, nxt, v);
        }
        if (maxH < hgt[v]) {
            maxH = hgt[v];
            nxt[u] = v;
        }
    }
    hgt[u] = maxH + (maxH > 0);
}

void solve() {
    // code...
    ll n, m;
    cin >> n >> m;
    vl graph[n + 1];
    while (m--) {
        ll a, b;
        cin >> a >> b;
        graph[a].pb(b);
    }
    vl hgt(n + 1, -1), nxt(n + 1);
    hgt[n] = 1;
    dfs(graph, hgt, nxt, 1);
    if (hgt[1] > 0) {
        cout << hgt[1] << nl;
        for (ll i = 1;; i = nxt[i]) {
            cout << i << " ";
            if (i == n) {
                break;
            }
        }
    } else {
        cout << "IMPOSSIBLE" << nl;
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
