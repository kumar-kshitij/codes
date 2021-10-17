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

ll sum(ll n) {
    n %= mod;
    return (n * (n + 1) % mod) * power(2, mod - 2, mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n;
        cin >> n;
        ll l = 1, res = 0;
        while (l <= n) {
            ll k = n / l;
            ll r = n / k;
            k %= mod;
            res = (res + (((mod + sum(r) - sum(l - 1)) % mod) * k) % mod) % mod;
            l = r + 1;
        }
        cout << res;
    }
    return 0;
}
