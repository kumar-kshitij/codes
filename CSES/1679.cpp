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

bool hasCycle(vl graph[], bool vis[], bool rst[], ll u) {
    vis[u] = true;
    rst[u] = true;
    for (auto v : graph[u]) {
        if (!vis[v] && hasCycle(graph, vis, rst, v) || rst[v]) {
            return true;
        }
    }
    return rst[u] = false;
}

void dfs(vl graph[], bool vis[], vl &st, ll u) {
    vis[u] = true;
    for (auto v : graph[u]) {
        if (!vis[v]) {
            dfs(graph, vis, st, v);
        }
    }
    st.pb(u);
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
        vl graph[n + 1];
        for (ll i = 0; i < m; i++) {
            ll a, b;
            cin >> a >> b;
            graph[a].pb(b);
        }
        bool vis[n + 1] = {0}, rst[n + 1] = {0};
        for (ll i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (hasCycle(graph, vis, rst, i)) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
        vl st;
        memset(vis, 0, sizeof(vis));
        for (ll i = 1; i <= n; i++) {
            if (!vis[i]) {
                dfs(graph, vis, st, i);
            }
        }
        while (!st.empty()) {
            cout << st.back() << " ";
            st.pop_back();
        }
    }
    return 0;
}
