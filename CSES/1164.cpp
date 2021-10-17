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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--) {
        // code...
        ll n;
        cin >> n;
        vector<vl> dur(n, vl(3));
        for (ll i = 0; i < n; i++) {
            cin >> dur[i][0] >> dur[i][1];
            dur[i][2] = i;
        }
        sort(dur.begin(), dur.end());
        map<ll, vl> mp;
        vl room(n);
        ll count = 0;
        for (ll i = 0; i < n; i++) {
            auto itr = mp.begin();
            if (!mp.empty() && itr->X < dur[i][0]) {
                room[dur[i][2]] = itr->Y.back();
                itr->Y.pop_back();
                if (itr->Y.empty()) {
                    mp.erase(itr);
                }
            } else {
                room[dur[i][2]] = ++count;
            }
            mp[dur[i][1]].pb(room[dur[i][2]]);
        }
        cout << count << nl;
        for (ll i = 0; i < n; i++) {
            cout << room[i] << " ";
        }
    }
    return 0;
}
