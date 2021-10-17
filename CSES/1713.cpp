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
        vl spf(sz), primes;
        for (ll i = 0; i < sz; i++) {
            spf[i] = i;
        }
        for (ll i = 2; i < sz; i++) {
            if (spf[i] == i) {
                primes.pb(i);
            }
            for (ll j = 0; j < primes.size() && primes[j] * i < sz; j++) {
                spf[primes[j] * i] = primes[j];
            }
        }
        ll n;
        cin >> n;
        while (n--) {
            ll x;
            cin >> x;
            unordered_map<ll, ll> freq;
            while (x > 1) {
                freq[spf[x]]++;
                x /= spf[x];
            }
            ll res = 1;
            for (auto itr = freq.begin(); itr != freq.end(); itr++) {
                res *= itr->Y + 1;
            }
            cout << res << nl;
        }
    }
    return 0;
}
