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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n, m;
        cin >> n >> m;
        ll si, sj;
        ll dist[n][m];
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                dist[i][j] = LLONG_MAX;
            }
        }
        char grid[n][m];
        queue<vl> q;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'M') {
                    q.push({i, j});
                    dist[i][j] = 0;
                } else if (grid[i][j] == 'A') {
                    si = i;
                    sj = j;
                }
            }
        }
        while (!q.empty()) {
            vl u = q.front();
            q.pop();
            for (ll k = 0; k < 4; k++) {
                ll x = u[0] + dx[k];
                ll y = u[1] + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' &&
                    dist[x][y] > dist[u[0]][u[1]] + 1) {
                    q.push({x, y});
                    dist[x][y] = dist[u[0]][u[1]] + 1;
                }
            }
        }
        ll prev[n][m];
        memset(prev, -1, sizeof(prev));
        q.push({si, sj, 0});
        prev[si][sj] = -2;
        while (!q.empty()) {
            vl u = q.front();
            q.pop();
            if ((u[0] == 0 || u[0] == n - 1 || u[1] == 0 || u[1] == m - 1) &&
                u[2] < dist[u[0]][u[1]]) {
                cout << "YES" << nl;
                string path;
                ll i = u[0], j = u[1];
                while (prev[i][j] != -2) {
                    ll k = prev[i][j];
                    ll diff = i * m + j - k;
                    if (diff == -1) {
                        path.pb('L');
                    } else if (diff == 1) {
                        path.pb('R');
                    } else if (diff == -m) {
                        path.pb('U');
                    } else {
                        path.pb('D');
                    }
                    i = k / m;
                    j = k % m;
                }
                reverse(path.begin(), path.end());
                cout << path.size() << nl << path;
                return 0;
            }
            for (ll k = 0; k < 4; k++) {
                ll x = u[0] + dx[k];
                ll y = u[1] + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' &&
                    prev[x][y] == -1) {
                    q.push({x, y, u[2] + 1});
                    prev[x][y] = u[0] * m + u[1];
                }
            }
        }
        cout << "NO";
    }
    return 0;
}
