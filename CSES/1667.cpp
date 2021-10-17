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
        vl graph[n + 1];
        for (ll i = 0; i < m; i++) {
            ll a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        bool flag = false;
        queue<ll> q;
        vl prev(n + 1, -1);
        q.push(1);
        prev[1] = 0;
        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            if (u == n) {
                flag = true;
                break;
            }
            for (ll v : graph[u]) {
                if (prev[v] == -1) {
                    q.push(v);
                    prev[v] = u;
                }
            }
        }
        if (flag) {
            vl path;
            ll i = n;
            while (i != 0) {
                path.pb(i);
                i = prev[i];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << nl;
            for (ll i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }
        } else {
            cout << "IMPOSSIBLE";
        }
    }
    return 0;
}
