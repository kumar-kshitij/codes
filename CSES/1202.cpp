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

void solve() {
    // code...
    ll n, m;
    cin >> n >> m;
    vector<pll> graph[n + 1];
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    vl dist(n + 1, 1e15), num(n + 1, 0), minf(n + 1, 0), maxf(n + 1, 0);
    vector<bool> vis(n + 1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[1] = 0;
    num[1] = 1;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        pll u = pq.top();
        pq.pop();
        if (vis[u.Y]) {
            continue;
        }
        vis[u.Y] = true;
        for (pll v : graph[u.Y]) {
            if (dist[v.X] == dist[u.Y] + v.Y) {
                num[v.X] = (num[v.X] + num[u.Y]) % mod;
                minf[v.X] = min(minf[v.X], minf[u.Y] + 1);
                maxf[v.X] = max(maxf[v.X], maxf[u.Y] + 1);
                pq.emplace(dist[v.X], v.X);
            } else if (dist[v.X] > dist[u.Y] + v.Y) {
                dist[v.X] = dist[u.Y] + v.Y;
                num[v.X] = num[u.Y];
                minf[v.X] = minf[u.Y] + 1;
                maxf[v.X] = maxf[u.Y] + 1;
                pq.emplace(dist[v.X], v.X);
            }
        }
    }
    cout << dist[n] << " " << num[n] << " " << minf[n] << " " << maxf[n] << nl;
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
