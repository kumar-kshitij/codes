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

ll n;

void dfs1(vl graph[], ll sn[], ll ts[], ll u, ll p) {
    for (ll v : graph[u]) {
        if (v != p) {
            dfs1(graph, sn, ts, v, u);
            sn[u] += sn[v];
            ts[u] += ts[v];
        }
    }
    ts[u] += sn[u];
    sn[u]++;
}

void dfs2(vl graph[], ll sn[], ll ts[], ll u, ll p) {
    for (ll v : graph[u]) {
        if (v != p) {
            ts[v] += ts[u] - ts[v] - sn[v] + n - sn[v];
            dfs2(graph, sn, ts, v, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        cin >> n;
        vl graph[n + 1];
        for (ll i = 0; i < n - 1; i++) {
            ll a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        ll sn[n + 1] = {0}, ts[n + 1] = {0};
        dfs1(graph, sn, ts, 1, 0);
        dfs2(graph, sn, ts, 1, 0);
        for (ll i = 1; i <= n; i++) {
            cout << ts[i] << " ";
        }
    }
    return 0;
}
