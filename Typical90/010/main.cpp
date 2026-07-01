#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, Q;
  cin >> N;

  vector<int> sum_a(N + 1, 0);  // クラス別n番目の生徒の点数合計
  vector<int> sum_b(N + 1, 0);  // n番目の生徒の点数合計

  for (int i = 1; i <= N; i++) {
    int c, p;
    cin >> c >> p;

    sum_a[i] = sum_a[i - 1];
    sum_b[i] = sum_b[i - 1];
    if (c == 1)
      sum_a[i] += p;
    else
      sum_b[i] += p;
  }

  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int from, to;
    cin >> from >> to;
    cout << sum_a[to] - sum_a[from - 1] << " ";
    cout << sum_b[to] - sum_b[from - 1] << '\n';
  }
}
