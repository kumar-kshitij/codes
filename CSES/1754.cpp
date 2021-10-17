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

void solve() {
    // code...
    ll a, b;
    cin >> a >> b;
    if ((a + b) % 3 != 0) {
        cout << "NO" << nl;
        return;
    }
    ll n = (a + b) / 3;
    if (a >= n && a <= 2 * n && b >= n && b <= 2 * n) {
        cout << "YES" << nl;
        return;
    }
    cout << "NO" << nl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
