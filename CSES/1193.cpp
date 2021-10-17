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
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n, m;
        cin >> n >> m;
        vector<vl> grid(n, vl(m));
        ll si, sj, di, dj;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                char ch;
                cin >> ch;
                if (ch == '.') {
                    grid[i][j] = -1;
                } else if (ch == 'A') {
                    si = i;
                    sj = j;
                    grid[i][j] = -1;
                } else if (ch == 'B') {
                    di = i;
                    dj = j;
                    grid[i][j] = -1;
                } else {
                    grid[i][j] = -2;
                }
            }
        }
        bool flag = false;
        queue<pll> q;
        q.push({si, sj});
        grid[si][sj] = -2;
        while (!q.empty()) {
            pll f = q.front();
            q.pop();
            if (f.X == di && f.Y == dj) {
                flag = true;
                break;
            }
            for (ll i = 0; i < 4; i++) {
                if (f.X + dx[i] >= 0 && f.X + dx[i] < n && f.Y + dy[i] >= 0 &&
                    f.Y + dy[i] < m && grid[f.X + dx[i]][f.Y + dy[i]] == -1) {
                    q.push({f.X + dx[i], f.Y + dy[i]});
                    grid[f.X + dx[i]][f.Y + dy[i]] = f.X * m + f.Y;
                }
            }
        }
        if (flag) {
            cout << "YES" << nl;
            string path;
            ll i = di, j = dj;
            while (grid[i][j] != -2) {
                ll diff = i * m + j - grid[i][j];
                if (diff == -1) {
                    path.pb('L');
                } else if (diff == 1) {
                    path.pb('R');
                } else if (diff == -m) {
                    path.pb('U');
                } else {
                    path.pb('D');
                }
                ll prev = grid[i][j];
                i = prev / m;
                j = prev % m;
            }
            reverse(path.begin(), path.end());
            cout << path.size() << nl << path;
        } else {
            cout << "NO";
        }
    }
    return 0;
}
