#include <bits/stdc++.h>
using namespace std;

int fileIndex = 1, prevPass = 0;

FILE *openFile(string fileName, string mode) {
  FILE *fp = fopen(fileName.c_str(), mode.c_str());
  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }
  return fp;
}

struct Transaction {
  int id;
  int amount;
  char customerName[4];
  int itemCategory;

  bool input(FILE **inFile) {
    if (*inFile == NULL) {
      return false;
    }
    int r = fscanf(*inFile, "%d %d %s %d", &id, &amount, customerName,
                   &itemCategory);
    if (r == 4) {
      return true;
    }
    fclose(*inFile);
    *inFile = r == 1 ? openFile(to_string(id) + ".txt", "r") : NULL;
    return false;
  }

  void output(FILE *outFile) {
    if (!outFile) {
      return;
    }
    fprintf(outFile, "%d %d %s %d\n", id, amount, customerName, itemCategory);
  }
};

string randStr(int len) {
  string res;
  for (int i = 0; i < len; i++) {
    char randChar = 'a' + (rand() % 26);
    res.push_back(randChar);
  }
  return res;
}

void createInput(int N) {
  FILE *outFile = openFile("input.txt", "w");
  for (int i = 0; i < N; i++) {
    Transaction trans;
    trans.id = i + 1;
    trans.amount = (rand() % 60000) + 1;
    strcpy(trans.customerName, randStr(3).c_str());
    trans.itemCategory = (rand() % 1500) + 1;
    trans.output(outFile);
  }
  fclose(outFile);
}

int initDiskBlocks(int N, int B) {
  int numBlocks = 0;
  FILE *inFile = openFile("input.txt", "r");
  prevPass = fileIndex;
  for (int i = 0; i < N;) {
    FILE *outFile = openFile(to_string(fileIndex) + ".txt", "w");
    for (int j = 0; i < N && j < B; i++, j++) {
      Transaction trans;
      trans.input(&inFile);
      trans.output(outFile);
    }
    fileIndex++;
    if (i < N) {
      fprintf(outFile, "%d.txt\n", fileIndex);
    }
    fclose(outFile);
    numBlocks++;
  }
  fclose(inFile);
  return numBlocks;
}

bool orderByAmt(Transaction &t1, Transaction &t2) {
  if (t1.amount == t2.amount) {
    return t1.id < t2.id;
  }
  return t1.amount < t2.amount;
}

int createRuns(int B, int M, int numBlocks) {
  int numRuns = 0;
  FILE *inFile = openFile(to_string(prevPass) + ".txt", "r");
  prevPass = fileIndex;
  for (int i = 0; i < numBlocks;) {
    vector<Transaction> run;
    for (int j = 0; i < numBlocks && j < M; i++, j++) {
      Transaction trans;
      while (trans.input(&inFile)) {
        run.push_back(trans);
      }
    }
    sort(run.begin(), run.end(), orderByAmt);
    for (int j = 0; j < run.size();) {
      FILE *outFile = openFile(to_string(fileIndex) + ".txt", "w");
      for (int k = 0; j < run.size() && k < B; j++, k++) {
        run[j].output(outFile);
      }
      fileIndex++;
      if (j < run.size()) {
        fprintf(outFile, "%d.txt\n", fileIndex);
      }
      fclose(outFile);
    }
    numRuns++;
  }
  return numRuns;
}

struct OrderByAmt {
  bool operator()(pair<Transaction, int> &p1, pair<Transaction, int> &p2) {
    if (p1.first.amount == p2.first.amount) {
      return p1.first.id > p2.first.id;
    }
    return p1.first.amount > p2.first.amount;
  }
};

void mergeRuns(int B, int M, int numRuns) {
  int runSize = M;
  while (numRuns > 1) {
    int count = 0, currPass = fileIndex;
    for (int i = 0; i < numRuns;) {
      vector<FILE *> inFiles;
      priority_queue<pair<Transaction, int>, vector<pair<Transaction, int>>,
                     OrderByAmt>
          pq;
      for (int j = 0; i < numRuns && j < M - 1; i++, j++) {
        FILE *inFile =
            openFile(to_string(prevPass + i * runSize) + ".txt", "r");
        inFiles.push_back(inFile);
        Transaction trans;
        trans.input(&inFile);
        pq.push({trans, j});
      }
      while (!pq.empty()) {
        FILE *outFile = openFile(to_string(fileIndex) + ".txt", "w");
        for (int j = 0; !pq.empty() && j < B; j++) {
          pair<Transaction, int> top = pq.top();
          pq.pop();
          top.first.output(outFile);
          if (top.first.input(&inFiles[top.second]) ||
              top.first.input(&inFiles[top.second])) {
            pq.push(top);
          }
        }
        fileIndex++;
        if (!pq.empty()) {
          fprintf(outFile, "%d.txt\n", fileIndex);
        }
        fclose(outFile);
      }
      count++;
    }
    numRuns = count;
    runSize *= M - 1;
    prevPass = currPass;
  }
}

void createOutput() {
  FILE *inFile = openFile(to_string(prevPass) + ".txt", "r");
  FILE *outFile = openFile("output.txt", "w");
  Transaction trans;
  while (trans.input(&inFile) || trans.input(&inFile)) {
    trans.output(outFile);
  }
  fclose(outFile);
}

int main() {
  int N, B, M;
  cin >> N >> B >> M;
  createInput(N);
  int numBlocks = initDiskBlocks(N, B);
  int numRuns = createRuns(B, M, numBlocks);
  mergeRuns(B, M, numRuns);
  createOutput();
  return 0;
}