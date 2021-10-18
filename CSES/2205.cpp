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
    vector<string> gc;
    string tmp(n, '0');
    cout << tmp << nl;
    gc.pb(tmp);
    tmp[n - 1] = '1';
    cout << tmp << nl;
    gc.pb(tmp);
    for (int i = n - 2; i >= 0; i--) {
        for (int j = gc.size() - 1; j >= 0; j--) {
            tmp = gc[j];
            tmp[i] = '1';
            cout << tmp << nl;
            gc.pb(tmp);
        }
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