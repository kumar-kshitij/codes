#include <bits/stdc++.h>
using namespace std;

struct process {
  int pid = 0, at = 0, bt = 0, rt = 0, ct = 0, wt = 0, tat = 0;
};

bool compareProcesses(process p1, process p2) { return p1.at < p2.at; }

int main() {
  int n, quantum;
  cin >> n >> quantum;
  process proc[n];
  for (int i = 0; i < n; i++) {
    proc[i].pid = i;
    cin >> proc[i].at >> proc[i].bt;
    proc[i].rt = proc[i].bt;
  }
  sort(proc, proc + n, compareProcesses);
  bool vis[n];
  for (int i = 0; i < n; i++) {
    vis[i] = false;
  }
  queue<int> Q;
  Q.push(0);
  vis[0] = true;
  int t = 0;
  while (!Q.empty()) {
    int k = Q.front();
    Q.pop();
    if (proc[k].rt >= quantum) {
      t += quantum;
      proc[k].rt -= quantum;
    } else {
      t += proc[k].rt;
      proc[k].rt = 0;
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i] && proc[i].at <= t && proc[i].rt > 0) {
        Q.push(i);
        vis[i] = true;
      }
    }
    if (proc[k].rt != 0) {
      Q.push(k);
    } else {
      proc[k].ct = t;
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