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

ll findSet(vl &parent, ll v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent, parent[v]);
}

void unionSets(vl &parent, ll a, ll b) {
    a = findSet(parent, a);
    b = findSet(parent, b);
    if (a != b) {
        parent[b] = a;
    }
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
        vl parent(n + 1);
        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
        }
        while (m--) {
            ll a, b;
            cin >> a >> b;
            unionSets(parent, a, b);
        }
        unordered_set<ll> s;
        for (ll i = 1; i <= n; i++) {
            s.insert(findSet(parent, i));
        }
        vl v(s.begin(), s.end());
        cout << v.size() - 1 << nl;
        for (ll i = 1; i < v.size(); i++) {
            cout << v[i - 1] << " " << v[i] << nl;
        }
    }
    return 0;
}
