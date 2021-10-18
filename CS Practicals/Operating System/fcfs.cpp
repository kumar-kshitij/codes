#include <bits/stdc++.h>
using namespace std;

struct process {
  int pid = 0, at = 0, bt = 0, ct = 0, wt = 0, tat = 0;
};

bool compareProcesses(process p1, process p2) { return p1.at < p2.at; }

int main() {
  int n;
  cin >> n;
  process proc[n];
  for (int i = 0; i < n; i++) {
    proc[i].pid = i;
    cin >> proc[i].at >> proc[i].bt;
  }
  sort(proc, proc + n, compareProcesses);
  int t = 0;
  double avgwt = 0, avgtat = 0;
  for (int i = 0; i < n; i++) {
    // if(proc[i].at <= t) {
    // 	t += proc[i].bt;
    // } else {
    // 	t = proc[i].at + proc[i].bt;
    // }

    t += proc[i].bt;

    proc[i].ct = t;
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