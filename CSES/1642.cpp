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
    vl a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vl> b;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = i + 1; j < n; j++) {
            b.push_back({a[i] + a[j], i + 1, j + 1});
        }
    }
    sort(b.begin(), b.end());
    ll m = b.size();
    for (ll i = 0; i < m - 1; i++) {
        ll y = x - b[i][0];
        ll lo = 0, hi = m - 1;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (b[mid][0] < y || (b[mid][0] == y && b[mid][1] <= b[i][2])) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (b[lo][0] != y || b[lo][1] <= b[i][2]) {
            continue;
        }
        cout << b[i][1] << " " << b[i][2] << " " << b[lo][1] << " " << b[lo][2]
             << nl;
        return;
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
