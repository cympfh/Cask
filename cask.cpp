#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define INF (1<<20)

#include "./em.h"
#include "./cvs.h"
#include "./words.h"

void solve(const string& line) {

  bool cvs_b1 = false,
       cvs_b2 = false;

  int cvs_pos1 = INF, cvs_pos2 = -1;
  for (string s: cvs_type1) {
    int pos = line.find(s);
    if (pos != string::npos) {
      cvs_pos1 = min(cvs_pos1, pos);
      cvs_b1 = true;
    }
  }
  for (string s: cvs_type2) {
    int pos = line.rfind(s);
    if (pos != string::npos) {
      cvs_pos2 = max(cvs_pos2, pos);
      cvs_b2 = true;
    }
  }

  kount ret;
  for (string w: awa) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(AWA));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(AWA));
    else ret.awa++;
  }
  for (string w: suk) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(SUK));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(SUK));
    else ret.suk++;
  }
  for (string w: kow) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(KOW));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(KOW));
    else ret.kow++;
  }
  for (string w: yas) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(YAS));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(YAS));
    else ret.yas++;
  }
  for (string w: iya) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(IYA));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(IYA));
    else ret.iya++;
  }
  for (string w: tak) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(TAK));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(TAK));
    else ret.tak++;
  }
  for (string w: odo) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(ODO));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(ODO));
    else ret.odo++;
  }
  for (string w: haj) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(HAJ));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(HAJ));
    else ret.haj++;
  }
  for (string w: yor) {
    int p = line.find(w);
    if (p == string::npos) continue;
    if (cvs_b1 && cvs_pos1 < p) ret = add(ret, shift(YOR));
    else if (cvs_b2 && cvs_pos2 > p) ret = add(ret, shift(YOR));
    else ret.yor++;
  }

  cout << ret.suk << ' '
       << ret.ika << ' '
       << ret.kow << ' '
       << ret.yas << ' '
       << ret.iya << ' '
       << ret.awa << ' '
       << ret.tak << ' '
       << ret.odo << ' '
       << ret.haj << ' '
       << ret.yor << endl;

}

int main(int argc, char**argv) {
  string line;
  if (argc == 1) {
    cout << "suk ika kow yas iya awa tak odo haj yor" << endl;
  }
  std::ifstream input("/dev/stdin");
  while (getline(input, line)) {
    solve(line);
  }
}
