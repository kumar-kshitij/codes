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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pll> graph[n + 1];
        while (m--) {
            ll a, b, c;
            cin >> a >> b >> c;
            graph[a].emplace_back(b, c);
        }
        vector<vl> dist(n + 1, vl(k, 1e15));
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.emplace(0, 1);
        while (!pq.empty()) {
            pll u = pq.top();
            pq.pop();
            if (dist[u.Y][k - 1] < u.X) {
                continue;
            }
            for (pll v : graph[u.Y]) {
                if (dist[v.X][k - 1] > u.X + v.Y) {
                    dist[v.X][k - 1] = u.X + v.Y;
                    pq.emplace(dist[v.X][k - 1], v.X);
                    sort(dist[v.X].begin(), dist[v.X].end());
                }
            }
        }
        for (ll i = 0; i < k; i++) {
            cout << dist[n][i] << " ";
        }
    }
    return 0;
}
