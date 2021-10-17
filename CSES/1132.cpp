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

ll dfs1(vl graph[], vl &hgt, ll u, ll p) {
    for (ll v : graph[u]) {
        if (v != p) {
            hgt[u] = max(hgt[u], dfs1(graph, hgt, v, u));
        }
    }
    return hgt[u] + 1;
}

void dfs2(vl graph[], vl &hgt, vl &dist, ll u, ll p) {
    ll max1 = -2, max2 = -2;
    for (ll v : graph[u]) {
        if (v != p) {
            if (hgt[v] >= max1) {
                max2 = max1;
                max1 = hgt[v];
            } else if (hgt[v] > max2) {
                max2 = hgt[v];
            }
        }
    }
    for (ll v : graph[u]) {
        if (v != p) {
            if (hgt[v] == max1) {
                dist[v] = max(dist[u], max2 + 1) + 1;
            } else {
                dist[v] = max(dist[u], max1 + 1) + 1;
            }
            dfs2(graph, hgt, dist, v, u);
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
        ll n;
        cin >> n;
        vl graph[n + 1];
        for (ll i = 0; i < n - 1; i++) {
            ll a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        vl hgt(n + 1, 0), dist(n + 1, 0);
        dfs1(graph, hgt, 1, 0);
        dfs2(graph, hgt, dist, 1, 0);
        for (ll i = 1; i <= n; i++) {
            cout << max(hgt[i], dist[i]) << " ";
        }
    }
    return 0;
}
