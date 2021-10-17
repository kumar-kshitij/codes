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
        ll dist[n + 1];
        fill(dist, dist + n + 1, LLONG_MAX);
        bool vis[n + 1] = {0};
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty()) {
            pll u = pq.top();
            pq.pop();
            if (vis[u.Y]) {
                continue;
            }
            vis[u.Y] = 1;
            for (pll v : graph[u.Y]) {
                if (dist[v.X] > dist[u.Y] + v.Y) {
                    dist[v.X] = dist[u.Y] + v.Y;
                    pq.push({dist[v.X], v.X});
                }
            }
        }
        for (ll i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
    }
    return 0;
}
