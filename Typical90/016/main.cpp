#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  long long N, A, B, C;
  cin >> N >> A >> B >> C;

  // 十分大きな値で初期化
  int ans = 100000;

  for (int a = 0; a <= 9999; a++) {
    for (int b = 0; b <= 9999; b++) {
      long long rest = N - A * a - B * b;
      if (rest < 0) continue;
      if (rest % C) continue;
      long long c = rest / C;

      if (a + b + c <= 9999) ans = min(ans, a + b + (int)c);
    }
  }
  cout << ans << endl;
  return 0;
}
