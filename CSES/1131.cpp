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

void dfs(vl graph[], vl &lvl, ll u) {
    for (ll v : graph[u]) {
        if (lvl[v] == -1) {
            lvl[v] = lvl[u] + 1;
            dfs(graph, lvl, v);
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
        vl lvl(n + 1, -1);
        lvl[1] = 0;
        dfs(graph, lvl, 1);
        ll maxL = -1, k;
        for (ll i = 1; i <= n; i++) {
            if (maxL < lvl[i]) {
                maxL = lvl[i];
                k = i;
            }
        }
        for (ll i = 1; i <= n; i++) {
            lvl[i] = -1;
        }
        lvl[k] = 0;
        dfs(graph, lvl, k);
        maxL = -1;
        for (ll i = 1; i <= n; i++) {
            maxL = max(maxL, lvl[i]);
        }
        cout << maxL;
    }
    return 0;
}
