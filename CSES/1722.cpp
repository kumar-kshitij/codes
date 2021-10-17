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

void mul(vl &a, vl &b) {
    ll p = (a[0] * b[0] % mod + a[1] * b[2] % mod) % mod;
    ll q = (a[0] * b[1] % mod + a[1] * b[3] % mod) % mod;
    ll r = (a[2] * b[0] % mod + a[3] * b[2] % mod) % mod;
    ll s = (a[2] * b[1] % mod + a[3] * b[3] % mod) % mod;
    a = {p, q, r, s};
}

void solve() {
    // code...
    ll n;
    cin >> n;
    if (n < 2) {
        cout << n << nl;
        return;
    } else {
        vl r{1, 1, 1, 0}, a{1, 1, 1, 0};
        n -= 2;
        while (n > 0) {
            if (n & 1) mul(r, a);
            mul(a, a);
            n >>= 1;
        }
        cout << r[0] << nl;
    }
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
