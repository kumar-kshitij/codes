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

void dfs(vector<vl> &next, vector<bool> &vis, vl &len, ll u) {
    vis[u] = true;
    if (!vis[next[u][0]]) {
        dfs(next, vis, len, next[u][0]);
    }
    len[u] = len[next[u][0]] + 1;
}

ll lift(vector<vl> &next, ll x, ll k) {
    ll j = 0;
    while (k > 0) {
        if (k & 1) {
            x = next[x][j];
        }
        j++;
        k /= 2;
    }
    return x;
}

void solve() {
    // code...
    ll n, q;
    cin >> n >> q;
    ll maxJ = ceil(log2(n));
    vector<vl> next(n + 1, vl(maxJ + 1));
    for (ll i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        next[i][0] = t;
    }
    for (ll j = 1; j <= maxJ; j++) {
        for (ll i = 1; i <= n; i++) {
            next[i][j] = next[next[i][j - 1]][j - 1];
        }
    }
    vl len(n + 1, 0);
    vector<bool> vis(n + 1, false);
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(next, vis, len, i);
        }
    }
    while (q--) {
        ll a, b;
        cin >> a >> b;
        ll c = lift(next, a, len[a]);
        if (lift(next, a, len[a] - len[b]) == b) {
            cout << len[a] - len[b] << nl;
        } else if (lift(next, c, len[c] - len[b]) == b) {
            cout << len[a] + len[c] - len[b] << nl;
        } else {
            cout << -1 << nl;
        }
    }
    return;
}

int main() {
    // auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    // auto end = chrono::steady_clock::now();
    // cout << nl << "Elapsed time : "
    //      << chrono::duration_cast<chrono::milliseconds>(end - start).count()
    //      << " ms" << nl;
    return 0;
}
