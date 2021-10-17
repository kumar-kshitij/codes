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

ll mod = 1000000007;
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

ll n, m;
vector<vector<char>> grid;
bool dfs(ll i, ll j) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '.') {
        return false;
    }
    grid[i][j] = '#';
    dfs(i, j + 1);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i - 1, j);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        cin >> n >> m;
        grid.resize(n, vector<char>(m));
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        ll res = 0;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                res += dfs(i, j);
            }
        }
        cout << res;
    }
    return 0;
}
