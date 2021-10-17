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
        ll n, x;
        cin >> n >> x;
        pll a[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i].X;
            a[i].Y = i + 1;
        }
        sort(a, a + n);
        ll i = 0, j = n - 1;
        while (i < j) {
            if (a[i].X + a[j].X < x) {
                i++;
            } else if (a[i].X + a[j].X > x) {
                j--;
            } else {
                cout << a[i].Y << " " << a[j].Y;
                return 0;
            }
        }
        cout << "IMPOSSIBLE";
    }
    return 0;
}
