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
    string s;
    cin >> s;
    ll n = s.size();
    vl fact(n + 1);
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    vl count(26, 0);
    for (ll i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    ll res = fact[n];
    for (ll i = 0; i < 26; i++) {
        if (count[i] > 0) {
            res = res * power(fact[count[i]], mod - 2, mod) % mod;
        }
    }
    cout << res << nl;
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
