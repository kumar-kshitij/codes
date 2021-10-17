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
        bool flag = true;
        queue<ll> q;
        vl grp(n + 1, 0);
        for (ll i = 1; flag && i <= n; i++) {
            if (!grp[i]) {
                q.push(i);
                grp[i] = 1;
                while (flag && !q.empty()) {
                    ll u = q.front();
                    q.pop();
                    for (ll v : graph[u]) {
                        if (grp[v] == 0) {
                            q.push(v);
                            grp[v] = grp[u] == 1 ? 2 : 1;
                        } else if (abs(grp[v] - grp[u]) == 0) {
                            flag = false;
                            break;
                        }
                    }
                }
            }
        }
        if (flag) {
            for (ll i = 1; i <= n; i++) {
                cout << grp[i] << " ";
            }
        } else {
            cout << "IMPOSSIBLE";
        }
    }
    return 0;
}
