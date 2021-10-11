#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
  vector<string> systems = {"Organic", "Semidetached", "Embedded"};
  vector<string> attributes = {"Required Reliability",
                               "Database Size",
                               "Product Complexity",
                               "Execution time constraint",
                               "Main storage Constraint",
                               "Virtual Machine Volatility",
                               "Computer Turnaround time",
                               "Analyst Capability",
                               "Application Experience",
                               "Programmer Capability",
                               "Programming Language Experience",
                               "Virtual Machine Experience",
                               "Use of Modern Programming Practice",
                               "Use of Software Tools",
                               "Required Development Schedule"};
  vector<string> ratings = {"Very Low", "Low",       "Nominal",
                            "High",     "Very High", "Extra High"};
  vector<string> phases = {"Product Design", "Programming",
                           "Integration and test"};

  vector<ld> a = {3.2, 3.0, 2.8};
  vector<ld> b = {1.05, 1.12, 1.20};
  vector<ld> c = {2.5, 2.5, 2.5};
  vector<ld> d = {0.38, 0.35, 0.32};
  vector<vector<ld>> attrVal = {
      {0.75, 0.88, 1.0, 1.15, 1.4, 0},   {0, 0.94, 1.0, 1.08, 1.16, 0},
      {0.7, 0.85, 1.0, 1.15, 1.3, 1.65}, {0, 0, 1.0, 1.11, 1.3, 1.66},
      {0, 0, 1.0, 1.06, 1.21, 1.53},     {0, 0.87, 1.0, 1.15, 1.3, 0},
      {0, 0.87, 1.0, 1.07, 1.15, 0},     {1.46, 1.19, 1.0, 0.86, 0.71, 0},
      {1.29, 1.13, 1.0, 0.91, 0.82, 0},  {1.42, 1.17, 1.0, 0.86, 0.7, 0},
      {1.14, 1.07, 1.0, 0.95, 0, 0},     {1.21, 1.10, 1.0, 0.9, 0, 0},
      {1.24, 1.10, 1.0, 0.91, 0.82, 0},  {1.24, 1.10, 1.0, 0.91, 0.83, 0},
      {1.23, 1.08, 1.0, 1.04, 1.10, 0},
  };
  vector<ld> projSize = {2, 8, 32, 128, 512};
  vector<vector<vector<ld>>> phaseVal = {
      {{19, 19, 19, 19, 19}, {63, 59, 55, 51, 51}, {18, 22, 26, 30, 30}},
      {{24, 25, 26, 27, 28}, {56, 52, 48, 44, 40}, {20, 23, 26, 29, 32}},
      {{30, 32, 34, 36, 38}, {48, 44, 40, 36, 32}, {22, 24, 26, 28, 30}}};

  ld kloc, sysIdx;
  unordered_map<ll, ll> attrRating;

  cout << "Input estimated project size (in KLOC): ";
  cin >> kloc;
  if (kloc < 2) {
    cout << "Invalid input.\n";
    exit(0);
  }

  if (kloc >= 300) {
    sysIdx = 2;
  } else if (kloc >= 50) {
    sysIdx = 1;
  } else {
    sysIdx = 0;
  }

  cout << "\n";
  for (ll i = 0; i < attributes.size(); i++) {
    cout << i << ") " << attributes[i] << "\n";
  }
  cout << attributes.size() << ") Continue...\n";
  while (1) {
    ll x, y;
    cout << "\nInput factor associated with the project (if any): ";
    cin >> x;
    if (x < 0 || x > attributes.size()) {
      cout << "Invalid input.\n";
      continue;
    }
    if (x == attributes.size()) break;
    unordered_set<ll> s;
    cout << attributes[x] << ": ";
    for (ll i = 0; i < attrVal[x].size(); i++) {
      if (attrVal[x][i] == 0) continue;
      cout << i << ") " << ratings[i] << ", ";
      s.insert(i);
    }
    cout << "\nInput rating of the chosen factor: ";
    cin >> y;
    if (s.count(y) == 0) {
      cout << "Invalid input.\n";
      continue;
    }
    attrRating[x] = y;
  }

  ld eaf = 1;
  for (auto &attr : attrRating) {
    eaf *= attrVal[attr.first][attr.second];
  }

  cout << "\n" << systems[sysIdx] << " system\n";

  ld effort = a[sysIdx] * pow(kloc, b[sysIdx]) * eaf;
  cout << "Effort: " << effort << " PM\n";

  ld tdev = c[sysIdx] * pow(effort, d[sysIdx]);
  cout << "Tdev: " << tdev << " M\n";

  cout << "Phase-wise time distribution for cost estimation:\n";
  ll j = lower_bound(projSize.begin(), projSize.end(), kloc) - projSize.begin();
  for (ll i = 0; i < phases.size(); i++) {
    ld y = j > 0 && j < projSize.size()
               ? phaseVal[sysIdx][i][j - 1] +
                     (phaseVal[sysIdx][i][j] - phaseVal[sysIdx][i][j - 1]) /
                         (projSize[j] - projSize[j - 1]) * kloc
               : (j == 0 ? phaseVal[sysIdx][i][j] : phaseVal[sysIdx][i][j - 1]);
    cout << phases[i] << ": " << y << "%, " << y * tdev / 100 << " M\n";
  }
  return 0;
}