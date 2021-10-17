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
    ll k;
    cin >> k;
    ll n = 0;
    while (((9 * (ld)n - 1) * pow(10, n) + 1) / 9 < k) {
        n++;
    }
    k -= ((9 * (ld)n - 10) * pow(10, n - 1) + 1) / 9;
    ll off = (k + n - 1) / n, idx = (n - (k % n)) % n;
    cout << (((ll)pow(10, n - 1) + off - 1) / (ll)pow(10, idx)) % 10 << nl;
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
