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
        ll sz = 1e6 + 1;
        vl fact(sz);
        fact[0] = 1;
        for (ll i = 1; i < sz; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        ll n;
        cin >> n;
        while (n--) {
            ll a, b;
            cin >> a >> b;
            cout << fact[a] *
                        (power(fact[b], mod - 2, mod) *
                         power(fact[a - b], mod - 2, mod) % mod) %
                        mod
                 << nl;
        }
    }
    return 0;
}
