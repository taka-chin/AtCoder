#include <iostream>
#include <vector>

using namespace std;

bool is_even(long long num) {
  if (num % 2) return false;
  return true;
}

int main() {
  int N;
  long long K;

  cin >> N >> K;
  vector<long long> A(N), B(N);

  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];

  long long diff = 0;
  for (int i = 0; i < N; i++) diff += abs(A[i] - B[i]);

  // 差が2の倍数かつdiff <=K
  if (is_even(K - diff) && diff <= K)
    cout << "Yes\n";
  else
    cout << "No\n";
}
