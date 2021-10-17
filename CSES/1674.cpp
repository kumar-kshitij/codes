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

class TreeNode {
   public:
    ll val;
    vector<TreeNode*> children;
};

ll dfs(vl& sub, TreeNode* node) {
    ll count = 0;
    for (ll i = 0; i < node->children.size(); i++) {
        count += dfs(sub, node->children[i]);
    }
    sub[node->val] = count;
    return count + 1;
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
        vector<TreeNode*> nodes(n + 1);
        for (ll i = 1; i <= n; i++) {
            nodes[i] = new TreeNode();
            nodes[i]->val = i;
        }
        for (ll i = 2; i <= n; i++) {
            ll p;
            cin >> p;
            nodes[p]->children.pb(nodes[i]);
        }
        vl sub(n + 1, 0);
        dfs(sub, nodes[1]);
        for (ll i = 1; i <= n; i++) {
            cout << sub[i] << " ";
        }
    }
    return 0;
}
