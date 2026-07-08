#include <iostream>
#include <string>

using namespace std;

bool isVaildParentheses(const string& S) {
  int balance = 0;
  for (char c : S) {
    if (c == '(')
      balance++;
    else
      balance--;
    if (balance < 0) return false;
  }
  if (balance != 0) return false;
  return true;
}

int main() {
  int N;
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
    if (isVaildParentheses(S)) cout << S << endl;
  }
}
