#include <deque>
#include <iostream>

using namespace std;

int main() {
  int N, Q;

  cin >> N >> Q;

  deque<int> A(N);

  for (auto& a : A) cin >> a;

  // O(10^5)
  for (int i = 0; i < Q; i++) {
    int T, x, y;
    cin >> T >> x >> y;
    if (T == 1)
      swap(A[x - 1], A[y - 1]);
    else if (T == 2) {
      int x = A.back();
      A.pop_back();
      A.push_front(x);
    } else
      cout << A[x - 1] << '\n';
  }
}
