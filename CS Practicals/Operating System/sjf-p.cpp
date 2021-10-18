#include <bits/stdc++.h>
using namespace std;

struct process {
  int pid = 0, at = 0, bt = 0, rt = 0, ct = 0, wt = 0, tat = 0;
};

int main() {
  int n;
  cin >> n;
  process proc[n];
  for (int i = 0; i < n; i++) {
    proc[i].pid = i;
    cin >> proc[i].at >> proc[i].bt;
    proc[i].rt = proc[i].bt;
  }
  int complete = 0;
  for (int t = 0; complete != n; t++) {
    int min = INT_MAX, k = -1;
    for (int i = 0; i < n; i++) {
      if (proc[i].at <= t && proc[i].rt > 0 && proc[i].rt < min) {
        min = proc[i].rt;
        k = i;
      }
    }
    if (k == -1) continue;
    proc[k].rt--;
    if (proc[k].rt == 0) {
      complete++;
      proc[k].ct = t + 1;
    }
  }
  double avgwt = 0, avgtat = 0;
  for (int i = 0; i < n; i++) {
    proc[i].tat = proc[i].ct - proc[i].at;
    proc[i].wt = proc[i].tat - proc[i].bt;
    avgwt += proc[i].wt;
    avgtat += proc[i].tat;

    cout << proc[i].pid << " " << proc[i].at << " " << proc[i].bt << " "
         << proc[i].ct << " " << proc[i].wt << " " << proc[i].tat << endl;
  }
  avgwt /= n;
  avgtat /= n;
  cout << avgwt << endl;
  cout << avgtat << endl;
  return 0;
}