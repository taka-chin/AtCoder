#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Grid {
 public:
  vector<string> g;

  Grid() = default;
  Grid(int h) : g(h) {}

  // map作成
  void input();

  // maps出力
  void print() const;

  // 高さ・長さ
  int height() const;
  int width() const;

  // 座標・文字含む
  bool inside(int y, int x) const;
  bool containsRow(int y, char c) const;
  bool containsCol(int x, char c) const;

  // map操作
  // 行削除
  void deleteRow(int y);
  // 列削除
  void deleteCol(int x);
};

inline void Grid::input() {
  for (auto& row : g) cin >> row;
}

inline void Grid::print() const {
  for (const auto& row : g) cout << row << '\n';
}

inline int Grid::height() const { return g.size(); }

inline int Grid::width() const { return g.empty() ? 0 : g[0].size(); }

inline bool Grid::inside(int y, int x) const {
  return 0 <= y && y < height() && 0 <= x && x < width();
}

inline bool Grid::containsRow(int y, char check) const {
  if (y < 0 || y >= height()) return false;
  for (char c : g[y]) {
    if (c == check) return true;
  }
  return false;
}

inline bool Grid::containsCol(int x, char check) const {
  if (x < 0 || x >= width()) return false;
  for (const auto& row : g) {
    if (row[x] == check) return true;
  }
  return false;
}

inline void Grid::deleteRow(int y) {
  if (y < 0 || y >= height()) return;
  g.erase(g.begin() + y);
}

inline void Grid::deleteCol(int x) {
  if (x < 0 || x >= width()) return;
  for (auto& row : g) row.erase(row.begin() + x);
}
