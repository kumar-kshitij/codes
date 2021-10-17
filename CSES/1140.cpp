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

bool comp(vl &a, vl &b) { return a[1] < b[1]; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n;
        cin >> n;
        vector<vl> proj(n, vl(3));
        for (ll i = 0; i < n; i++) {
            cin >> proj[i][0] >> proj[i][1] >> proj[i][2];
        }
        sort(proj.begin(), proj.end(), comp);
        vl dp(n);
        dp[0] = proj[0][2];
        for (ll i = 1; i < n; i++) {
            ll lo = 0;
            ll hi = i - 1;
            while (lo < hi) {
                ll mid = lo + (hi - lo + 1) / 2;
                if (proj[mid][1] < proj[i][0]) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            dp[i] = max(dp[i - 1],
                        (proj[lo][1] < proj[i][0] ? dp[lo] : 0) + proj[i][2]);
        }
        cout << dp[n - 1];
    }
    return 0;
}
