#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define X first
#define Y second
#define pb emplace_back
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

void solve() {
    // code...
    ll n, x;
    cin >> n >> x;
    vector<pll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].X;
        a[i].Y = i + 1;
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < n - 2; i++) {
        for (ll j = i + 1; j < n - 1; j++) {
            ll y = x - a[i].X - a[j].X;
            ll lo = j + 1, hi = n - 1;
            while (lo <= hi) {
                ll mid = lo + (hi - lo) / 2;
                if (a[mid].X < y) {
                    lo = mid + 1;
                } else if (a[mid].X > y) {
                    hi = mid - 1;
                } else {
                    cout << a[i].Y << " " << a[j].Y << " " << a[mid].Y << nl;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
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
