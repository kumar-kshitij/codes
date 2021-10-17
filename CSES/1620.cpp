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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n, p;
        cin >> n >> p;
        vl k(n);
        ll lo = 0, hi = INT_MAX;
        for (ll i = 0; i < n; i++) {
            cin >> k[i];
            hi = min(hi, k[i]);
        }
        hi *= p;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            ll count = 0;
            for (ll i = 0; i < n; i++) {
                count += mid / k[i];
            }
            if (count < p) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        cout << lo << nl;
    }
    return 0;
}
