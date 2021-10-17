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

ll n, maxJ, timer;
vl tin, tout, cnt, ex;
vector<vl> adj, up;

void dfs(ll u, ll p) {
    tin[u] = ++timer;
    up[u][0] = p;
    for (ll j = 1; j <= maxJ; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }
    for (ll v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    tout[u] = ++timer;
}

bool is_ancestor(ll u, ll v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (ll j = maxJ; j >= 0; j--) {
        if (!is_ancestor(up[u][j], v)) {
            u = up[u][j];
        }
    }
    return up[u][0];
}

void dfs2(ll u, ll p) {
    for (ll v : adj[u]) {
        if (v != p) {
            dfs2(v, u);
            cnt[u] += cnt[v];
        }
    }
}

void solve() {
    // code...
    ll m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    tin.resize(n + 1);
    tout.resize(n + 1);
    timer = 0;
    maxJ = ceil(log2(n));
    up.resize(n + 1, vl(maxJ + 1));
    dfs(1, 1);
    cnt.resize(n + 1, 0);
    ex.resize(n + 1, 0);
    while (m--) {
        ll a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
        ll l = lca(a, b);
        cnt[l] -= 2;
        ex[l]++;
    }
    dfs2(1, 1);
    for (ll i = 1; i <= n; i++) {
        cout << cnt[i] + ex[i] << " ";
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
