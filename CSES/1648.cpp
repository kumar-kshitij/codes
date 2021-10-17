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

ll mod = 1000000007;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n, q;
        cin >> n >> q;
        vl x(n + 1), BIT(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            cin >> x[i];
            for (ll j = i; j <= n; j += j & -j) {
                BIT[j] += x[i];
            }
        }
        while (q--) {
            ll a, b, c;
            cin >> a >> b >> c;
            if (a == 1) {
                for (ll j = b; j <= n; j += j & -j) {
                    BIT[j] += c - x[b];
                }
                x[b] = c;
            } else {
                ll sum = 0;
                for (ll j = c; j > 0; j -= j & -j) {
                    sum += BIT[j];
                }
                for (ll j = b - 1; j > 0; j -= j & -j) {
                    sum -= BIT[j];
                }
                cout << sum << nl;
            }
        }
    }
    return 0;
}
