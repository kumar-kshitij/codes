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

bool comp(pll a, pll b) { return a.Y < b.Y; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n;
        cin >> n;
        pll mov[n];
        for (ll i = 0; i < n; i++) {
            cin >> mov[i].X >> mov[i].Y;
        }
        sort(mov, mov + n, comp);
        ll res = 0, bnd = 0;
        for (ll i = 0; i < n; i++) {
            if (mov[i].X >= bnd) {
                res++;
                bnd = mov[i].Y;
            }
        }
        cout << res;
    }
    return 0;
}
