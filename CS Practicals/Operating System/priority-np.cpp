#include <bits/stdc++.h>
using namespace std;

struct process {
  int pid = 0, at = 0, bt = 0, p = 0, ct = 0, wt = 0, tat = 0;
};

void swap(process &p1, process &p2) {
  process temp = p1;
  p1 = p2;
  p2 = temp;
}

bool compareProcesses(process p1, process p2) {
  if (p1.at == p2.at) {
    return p1.p < p2.p;
  }
  return p1.at < p2.at;
}

int main() {
  int n;
  cin >> n;
  process proc[n];
  for (int i = 0; i < n; i++) {
    proc[i].pid = i;
    cin >> proc[i].at >> proc[i].bt >> proc[i].p;
  }
  sort(proc, proc + n, compareProcesses);
  int t = proc[0].at;
  t = proc[0].ct = t + proc[0].bt;
  proc[0].tat = proc[0].ct - proc[0].at;
  proc[0].wt = proc[0].tat - proc[0].bt;
  for (int i = 1; i < n; i++) {
    int min = proc[i].p, k = i;
    for (int j = i; j < n; j++) {
      if (proc[j].at <= t && proc[j].p < min) {
        min = proc[j].p;
        k = j;
      }
    }
    swap(proc[i], proc[k]);
    t = proc[i].ct = t + proc[i].bt;
    proc[i].tat = proc[i].ct - proc[i].at;
    proc[i].wt = proc[i].tat - proc[i].bt;
  }
  double avgwt = 0, avgtat = 0;
  for (int i = 0; i < n; i++) {
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