#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int> > A(H, vector<int>(W));

  for (auto& row : A)
    for (auto& col : row) cin >> col;

  vector<int> sum_row(H);
  vector<int> sum_col(W);

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      sum_row[y] += A[y][x];
      sum_col[x] += A[y][x];
    }
  }

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (x) cout << ' ';
      cout << sum_row[y] + sum_col[x] - A[y][x];
    }
    cout << '\n';
  }
}
