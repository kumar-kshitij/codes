#include <bits/stdc++.h>
using namespace std;

#define ll long long

void findLongestPath(vector<ll> &src, vector<ll> &e, vector<vector<ll>> &adj,
                     vector<ll> &dur) {
  priority_queue<pair<ll, ll>> pq;
  for (auto s : src) {
    e[s] = 0;
    pq.push({e[s], s});
  }
  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();
    ll t = top.first, u = top.second;
    if (t < e[u]) continue;
    for (auto v : adj[u]) {
      if (e[v] < t + dur[u]) {
        e[v] = t + dur[u];
        pq.push({e[v], v});
      }
    }
  }
}

int main() {
  cout << "Input no. of activities: ";
  ll n;
  cin >> n;

  cout << "\nInput predecessor activities:\n";
  vector<ll> src, dst;
  vector<vector<ll>> adj(n), radj(n);
  for (ll i = 0; i < n; i++) {
    ll np;
    cin >> np;
    if (np == 0) {
      src.push_back(i);
      continue;
    }
    for (ll j = 0; j < np; j++) {
      ll p;
      cin >> p;
      adj[p].push_back(i);
      radj[i].push_back(p);
    }
  }
  for (ll i = 0; i < n; i++) {
    if (adj[i].size() == 0) dst.push_back(i);
  }

  cout << "\nInput duration of activities:\n";
  vector<ll> dur(n);
  for (ll i = 0; i < n; i++) {
    cin >> dur[i];
  }

  vector<ll> e(n), l(n);
  findLongestPath(src, e, adj, dur);
  findLongestPath(dst, l, radj, dur);

  ll pct = 0;
  for (ll i = 0; i < n; i++) {
    pct = max(pct, e[i] + dur[i]);
  }
  cout << "\nProject Completion Time: " << pct << "\n\n";

  vector<ll> ca;
  for (ll i = 0; i < n; i++) {
    ll ej = pct;
    for (auto j : adj[i]) {
      ej = min(ej, e[j]);
    }
    ll es = e[i], ef = es + dur[i], ls = pct - l[i] - dur[i], lf = ls + dur[i],
       tf = ls - es, ff = ej - ef;
    cout << (char)(i + 'A') << ": ES=" << es << ", EF=" << ef << ", LS=" << ls
         << ", LF=" << lf << ", TF=" << tf << ", FF=" << ff << "\n";
    if (es == ls) {
      ca.push_back(i);
    }
  }
  cout << "\nCritical Activities: ";
  for (ll i = 0; i < ca.size(); i++) {
    cout << (char)(ca[i] + 'A') << (i < ca.size() - 1 ? ", " : "");
  }
  sort(ca.begin(), ca.end(), [&e](ll a, ll b) { return e[a] < e[b]; });
  cout << "\nCritical Path: ";
  for (ll i = 0; i < ca.size(); i++) {
    cout << (char)(ca[i] + 'A') << (i < ca.size() - 1 ? " - " : "");
  }
  return 0;
}
