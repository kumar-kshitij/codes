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
    ll n;
    cin >> n;
    if (((n * (n + 1)) / 2) % 2 == 0) {
        vl s[2];
        s[0].pb(n);
        ll i = 1, j = n - 1;
        while (j > 1) {
            s[i].pb(j);
            s[i].pb(j - 1);
            i = !i;
            j -= 2;
        }
        if (j > 0) {
            s[i].pb(j);
        }
        cout << "YES" << nl;
        for (ll k = 0; k < 2; k++) {
            cout << s[k].size() << nl;
            for (ll l = 0; l < s[k].size(); l++) {
                cout << s[k][l] << " ";
            }
            cout << nl;
        }
    } else {
        cout << "NO" << nl;
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
