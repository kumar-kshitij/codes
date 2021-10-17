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

void dfs(vl graph[], vl &tour, ll first[], ll height[], ll u, ll p, ll h) {
    first[u] = tour.size();
    tour.pb(u);
    height[u] = h;
    for (ll v : graph[u]) {
        if (v != p) {
            dfs(graph, tour, first, height, v, u, h + 1);
            tour.pb(u);
        }
    }
}

void build(vl &tree, vl &tour, ll height[], ll n, ll s, ll e) {
    if (s == e) {
        tree[n] = tour[s];
    } else {
        ll m = (s + e) / 2;
        build(tree, tour, height, 2 * n, s, m);
        build(tree, tour, height, 2 * n + 1, m + 1, e);
        tree[n] = height[tree[2 * n]] < height[tree[2 * n + 1]]
                      ? tree[2 * n]
                      : tree[2 * n + 1];
    }
}

ll query(vl &tree, ll height[], ll n, ll s, ll e, ll l, ll r) {
    if (r < s || e < l) {
        return 0;
    }
    if (l <= s && e <= r) {
        return tree[n];
    }
    ll m = (s + e) / 2;
    ll a = query(tree, height, 2 * n, s, m, l, r);
    ll b = query(tree, height, 2 * n + 1, m + 1, e, l, r);
    return height[a] < height[b] ? a : b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n, q;
        cin >> n >> q;
        vl graph[n + 1];
        for (ll i = 0; i < n - 1; i++) {
            ll a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        vl tour;
        ll first[n + 1], height[n + 1];
        memset(first, -1, sizeof(first));
        height[0] = INT_MAX;
        dfs(graph, tour, first, height, 1, 0, 0);
        vl tree;
        tree.resize(tour.size() * 4);
        build(tree, tour, height, 1, 0, tour.size() - 1);
        while (q--) {
            ll a, b;
            cin >> a >> b;
            if (first[a] > first[b]) {
                swap(a, b);
            }
            ll c =
                query(tree, height, 1, 0, tour.size() - 1, first[a], first[b]);
            cout << height[a] + height[b] - 2 * height[c] << nl;
        }
    }
    return 0;
}
