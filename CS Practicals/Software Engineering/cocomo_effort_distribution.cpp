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
  vector<string> phases = {"Product Design", "Detailed Design",
                           "Code and Unit Testing", "Integration Testing"};

  vector<ld> a = {3.2, 3.0, 2.8};
  vector<ld> b = {1.05, 1.12, 1.20};
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
  vector<vector<vector<ld>>> phaseVal = {{{16, 16, 16, 16, 16},
                                          {26, 25, 24, 23, 23},
                                          {42, 40, 38, 36, 36},
                                          {16, 19, 22, 25, 25}},
                                         {{17, 17, 17, 17, 17},
                                          {27, 26, 25, 24, 23},
                                          {37, 35, 33, 31, 29},
                                          {19, 22, 25, 28, 31}},
                                         {{18, 18, 18, 18, 18},
                                          {28, 27, 26, 25, 24},
                                          {32, 30, 28, 26, 24},
                                          {22, 25, 28, 31, 34}}};

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
  for (auto& attr : attrRating) {
    eaf *= attrVal[attr.first][attr.second];
  }

  cout << "\n" << systems[sysIdx] << " system\n";

  ld effort = a[sysIdx] * pow(kloc, b[sysIdx]) * eaf;
  cout << "Effort: " << effort << " PM\n";

  cout << "Phase-wise effort distribution for cost estimation:\n";
  ll j = lower_bound(projSize.begin(), projSize.end(), kloc) - projSize.begin();
  for (ll i = 0; i < phases.size(); i++) {
    ld y = j > 0 && j < projSize.size()
               ? phaseVal[sysIdx][i][j - 1] +
                     (phaseVal[sysIdx][i][j] - phaseVal[sysIdx][i][j - 1]) /
                         (projSize[j] - projSize[j - 1]) * kloc
               : (j == 0 ? phaseVal[sysIdx][i][j] : phaseVal[sysIdx][i][j - 1]);
    cout << phases[i] << ": " << y << "%, " << y * effort / 100 << " PM\n";
  }
  return 0;
}