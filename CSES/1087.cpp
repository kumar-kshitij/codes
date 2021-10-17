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

ll mod = 1000000007;
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
        string res;
        unordered_set<char> c;
        for (ll i = 0; i < s.size(); i++) {
            c.insert(s[i]);
            if (c.size() == 4) {
                res.pb(s[i]);
                c.clear();
            }
        }
        char ch[] = {'A', 'C', 'G', 'T'};
        for (ll i = 0; i < 4; i++) {
            if (c.find(ch[i]) == c.end()) {
                res.pb(ch[i]);
                break;
            }
        }
        cout << res;
    }
    return 0;
}
