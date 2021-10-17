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
        string s;
        cin >> s;
        vl count(26, 0);
        for (ll i = 0; i < s.size(); i++) {
            count[s[i] - 'A']++;
        }
        ll odds = 0, k = -1;
        for (ll i = 0; i < count.size(); i++) {
            if (count[i] % 2 == 1) {
                odds++;
                k = i;
            }
        }
        if (odds > 1) {
            cout << "NO SOLUTION";
        } else {
            string res;
            for (ll i = 0; i < count.size(); i++) {
                res.append(count[i] / 2, 'A' + i);
            }
            ll i = res.size() - 1;
            if (k != -1) {
                res.pb('A' + k);
            }
            while (i >= 0) {
                res.pb(res[i--]);
            }
            cout << res;
        }
    }
    return 0;
}
