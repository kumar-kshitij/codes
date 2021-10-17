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

bool hasCycle(vl graph[], ll par[], ll bnd[], ll u) {
    for (auto v : graph[u]) {
        if (par[v] == -1) {
            par[v] = u;
            if (hasCycle(graph, par, bnd, v)) {
                return true;
            }
        } else {
            if (v != par[u]) {
                bnd[0] = v;
                bnd[1] = u;
                return true;
            }
        }
    }
    return false;
}

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
        ll par[n + 1];
        memset(par, -1, sizeof(par));
        ll bnd[] = {-1, -1};
        for (ll i = 1; i <= n; i++) {
            if (par[i] == -1) {
                par[i] = 0;
                if (hasCycle(graph, par, bnd, i)) {
                    vl trip(1, bnd[0]);
                    for (ll j = bnd[1]; j != bnd[0]; j = par[j]) {
                        trip.pb(j);
                    }
                    trip.pb(bnd[0]);
                    cout << trip.size() << nl;
                    for (ll j = 0; j < trip.size(); j++) {
                        cout << trip[j] << " ";
                    }
                    return 0;
                }
            }
        }
        cout << "IMPOSSIBLE";
    }
    return 0;
}
