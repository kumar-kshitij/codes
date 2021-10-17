#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define X first
#define Y second
#define pb emplace_back
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

class Trie {
   public:
    bool isLeaf;
    vector<Trie*> next;

    Trie() {
        isLeaf = false;
        next.resize(26, nullptr);
    }

    void insert(string& w) {
        Trie* curr = this;
        for (ll i = 0; i < w.size(); i++) {
            if (!curr->next[w[i] - 'a']) {
                curr->next[w[i] - 'a'] = new Trie();
            }
            curr = curr->next[w[i] - 'a'];
        }
        curr->isLeaf = true;
    }
};

void solve() {
    // code...
    string s;
    cin >> s;
    ll k;
    cin >> k;
    Trie* root = new Trie();
    while (k--) {
        string w;
        cin >> w;
        root->insert(w);
    }
    ll n = s.size();
    vl dp(n + 1, 0);
    dp[n] = 1;
    for (ll i = n - 1; i >= 0; i--) {
        Trie* curr = root;
        for (ll j = i; curr && j < n; j++) {
            curr = curr->next[s[j] - 'a'];
            if (curr && curr->isLeaf) {
                dp[i] = (dp[i] + dp[j + 1]) % mod;
            }
        }
    }
    cout << dp[0] << nl;
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
