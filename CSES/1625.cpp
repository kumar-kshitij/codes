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

unordered_map<char, ll> di;
bool vis[7][7];

void dfs(string &s, ll &res, ll i, ll r, ll c) {
    if (r == 6 && c == 0) {
        res += (i == s.size());
        return;
    }
    bool flag = (((r == 0 && vis[r + 1][c]) || (r == 6 && vis[r - 1][c])) &&
                 c > 0 && c < 6 && !vis[r][c - 1] && !vis[r][c + 1]) ||
                (((c == 0 && vis[r][c + 1]) || (c == 6 && vis[r][c - 1])) &&
                 r > 0 && r < 6 && !vis[r - 1][c] && !vis[r + 1][c]) ||
                (r > 0 && r < 6 && c > 0 && c < 6 && vis[r + 1][c] &&
                 vis[r - 1][c] && !vis[r][c + 1] && !vis[r][c - 1]) ||
                (r > 0 && r < 6 && c > 0 && c < 6 && !vis[r + 1][c] &&
                 !vis[r - 1][c] && vis[r][c + 1] && vis[r][c - 1]);
    if (flag) {
        return;
    }
    vis[r][c] = true;
    if (s[i] != '?') {
        ll nr = r + dx[di[s[i]]], nc = c + dx[di[s[i]] + 1];
        if (!(nr < 0 || nr >= 7 || nc < 0 || nc >= 7 || vis[nr][nc])) {
            dfs(s, res, i + 1, nr, nc);
        }
    } else {
        for (ll j = 0; j < 4; j++) {
            ll nr = r + dx[j], nc = c + dx[j + 1];
            if (nr < 0 || nr >= 7 || nc < 0 || nc >= 7 || vis[nr][nc]) {
                continue;
            }
            dfs(s, res, i + 1, nr, nc);
        }
    }
    vis[r][c] = false;
}

void solve(string &s) {
    // code...
    di['D'] = 1;
    di['U'] = 3;
    di['L'] = 2;
    di['R'] = 0;
    ll res = 0;
    memset(vis, 0, sizeof(vis));
    dfs(s, res, 0, 0, 0);
    cout << res << nl;
    return;
}

int main() {
    // auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        string s;
        cin >> s;
        solve(s);
    }
    // auto end = chrono::steady_clock::now();
    // cout << nl << "Elapsed time : "
    //      << chrono::duration_cast<chrono::milliseconds>(end - start).count()
    //      << " ms" << nl;
    return 0;
}
