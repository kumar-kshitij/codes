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
        vector<pll> graph[n + 1];
        for (ll i = 0; i < m; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            graph[a].pb({b, c});
        }
        vector<vl> dist(n + 1, vl(2, LLONG_MAX));
        vector<vector<bool>> vis(n + 1, vector<bool>(2, false));
        priority_queue<vl, vector<vl>, greater<vl>> pq;
        dist[1][1] = 0;
        pq.push({0, 1, 1});
        while (!pq.empty()) {
            vl u = pq.top();
            pq.pop();
            if (vis[u[1]][u[2]]) {
                continue;
            }
            vis[u[1]][u[2]] = true;
            for (pll v : graph[u[1]]) {
                if (dist[v.X][u[2]] > dist[u[1]][u[2]] + v.Y) {
                    dist[v.X][u[2]] = dist[u[1]][u[2]] + v.Y;
                    pq.push({dist[v.X][u[2]], v.X, u[2]});
                }
                if (u[2] == 1 && dist[v.X][0] > dist[u[1]][1] + v.Y / 2) {
                    dist[v.X][0] = dist[u[1]][1] + v.Y / 2;
                    pq.push({dist[v.X][0], v.X, 0});
                }
            }
        }
        cout << dist[n][0];
    }
    return 0;
}
