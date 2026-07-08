#include <iostream>
#include <set>

using namespace std;

int main() {
  int N;
  cin >> N;

  set<int> rates;

  for (int i = 0; i < N; i++) {
    int rate;
    cin >> rate;
    rates.insert(rate);
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int score;
    cin >> score;
    // 2^30で初期化
    int dissatisfaction = 1 << 30;
    auto it = rates.lower_bound(score);
    if (it != rates.end()) {
      dissatisfaction = abs(score - *it);
    }
    if (it != rates.begin()) {
      --it;
      dissatisfaction = min(dissatisfaction, abs(score - *it));
    }
    cout << dissatisfaction << endl;
  }
}

