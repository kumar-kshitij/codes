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

bool isSafe(vector<string> &grid, vector<pll> &loc, ll r, ll c) {
    if (grid[r][c] == '*') {
        return false;
    }
    for (ll i = 0; i < loc.size(); i++) {
        if (r == loc[i].X || c == loc[i].Y ||
            abs(r - loc[i].X) == abs(c - loc[i].Y)) {
            return false;
        }
    }
    return true;
}

void dfs(vector<string> &grid, vector<pll> &loc, ll &res, ll r) {
    if (r == 8) {
        res += (loc.size() == 8);
        return;
    }
    for (ll i = 0; i < 8; i++) {
        if (isSafe(grid, loc, r, i)) {
            loc.emplace_back(r, i);
            dfs(grid, loc, res, r + 1);
            loc.pop_back();
        }
    }
}

void solve() {
    // code...
    vector<string> grid(8);
    for (ll i = 0; i < 8; i++) {
        cin >> grid[i];
    }
    vector<pll> loc;
    ll res = 0;
    dfs(grid, loc, res, 0);
    cout << res << nl;
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
