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
        ll n;
        cin >> n;
        queue<pll> q;
        unordered_set<ll> vis;
        q.push({n, 0});
        vis.insert(n);
        while (!q.empty()) {
            pll f = q.front();
            q.pop();
            if (f.X == 0) {
                cout << f.Y;
                break;
            }
            string s = to_string(f.X);
            for (ll i = 0; i < s.size(); i++) {
                ll next = f.X - s[i] + '0';
                if (vis.find(next) == vis.end()) {
                    q.push({next, f.Y + 1});
                    vis.insert(next);
                }
            }
        }
    }
    return 0;
}
