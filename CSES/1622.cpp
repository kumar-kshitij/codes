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

void dfs(string &s, vector<bool> &vis, vector<string> &res, string &tmp, ll n) {
    if (n == 0) {
        res.pb(tmp);
        return;
    }
    for (ll i = 0; i < s.size(); i++) {
        if (vis[i] || (i > 0 && s[i] == s[i - 1] && !vis[i - 1])) {
            continue;
        }
        vis[i] = true;
        tmp.pb(s[i]);
        dfs(s, vis, res, tmp, n - 1);
        tmp.pop_back();
        vis[i] = false;
    }
}

void solve() {
    // code...
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int n = s.size();
    vector<bool> vis(n, false);
    vector<string> res;
    string tmp;
    dfs(s, vis, res, tmp, n);
    cout << res.size() << nl;
    for (ll i = 0; i < res.size(); i++) {
        cout << res[i] << nl;
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
