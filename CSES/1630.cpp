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

bool comp(pll a, pll b) {
    if (a.X == b.X) {
        return a.Y > b.Y;
    }
    return a.X < b.X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n;
        cin >> n;
        vector<pll> tasks(n);
        for (ll i = 0; i < n; i++) {
            cin >> tasks[i].X >> tasks[i].Y;
        }
        sort(tasks.begin(), tasks.end(), comp);
        ll res = 0, f = 0;
        for (ll i = 0; i < n; i++) {
            f += tasks[i].X;
            res += tasks[i].Y - f;
        }
        cout << res;
    }
    return 0;
}
