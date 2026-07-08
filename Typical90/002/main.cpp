#include <iostream>
#include <string>

using namespace std;

bool is_check(const string& S) {
  int count = 0;
  for (auto &c : S) {
    if (c == '(')
      count++;
    else
      count--;
    if (count < 0) return false;
  }
  if (count != 0) return false;
  return true;
}

int main() {
  int N ;
  cin >> N;
  // Nbit全探索
  for (int bit = 0; bit < (1 << N); bit++) {
    string S;
    for (int i = N - 1; i >= 0; i--) {
      if (!(bit & (1 << i)))
        S += '(';
      else
        S += ')';
    }
    if (is_check(S)) cout << S << endl;
  }
}
