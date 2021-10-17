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

bool dfs(vl graph[], bool vis[], set<ll> &s, ll u) {
    if (s.find(u) != s.end()) {
        return true;
    }
    for (ll v : graph[u]) {
        if (!vis[v]) {
            vis[v] = true;
            if (dfs(graph, vis, s, v)) {
                return true;
            }
        }
    }
    return false;
}

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
        vl graph[n + 1];
        for (ll i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
            graph[edges[i][1]].pb(edges[i][0]);
        }
        ll dist[n + 1];
        dist[1] = 0;
        for (ll i = 2; i <= n; i++) {
            dist[i] = LLONG_MIN;
        }
        for (ll i = 0; i < n - 1; i++) {
            for (ll j = 0; j < m; j++) {
                if (dist[edges[j][0]] != LLONG_MIN &&
                    dist[edges[j][1]] < dist[edges[j][0]] + edges[j][2]) {
                    dist[edges[j][1]] = dist[edges[j][0]] + edges[j][2];
                }
            }
        }
        set<ll> s;
        for (ll j = 0; j < m; j++) {
            if (dist[edges[j][0]] != LLONG_MIN &&
                dist[edges[j][1]] < dist[edges[j][0]] + edges[j][2]) {
                s.insert(edges[j][1]);
            }
        }
        bool vis[n + 1] = {0};
        if (dfs(graph, vis, s, n)) {
            cout << -1;
        } else {
            cout << dist[n];
        }
    }
    return 0;
}
