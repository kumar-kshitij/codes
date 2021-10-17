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

pll dfs(vl graph[], vector<bool> &vis, ll u) {
    vector<pll> cnt;
    pll tot = {0, 0};
    for (ll v : graph[u]) {
        if (!vis[v]) {
            vis[v] = true;
            pll c = dfs(graph, vis, v);
            cnt.pb(c);
            tot.X += c.X;
            tot.Y += c.Y;
        }
    }
    ll x = 0;
    for (ll i = 0; i < cnt.size(); i++) {
        x = max(x, tot.X - cnt[i].X + cnt[i].Y);
    }
    return {x + (cnt.size() > 0), max(tot.X, tot.Y)};
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
        vector<bool> vis(n + 1, false);
        vis[1] = true;
        pll res = dfs(graph, vis, 1);
        cout << max(res.X, res.Y);
    }
    return 0;
}
