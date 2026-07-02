#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  //隣接リスト N頂点M辺
  vector<vector<int>> graph(N + 1);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  int cnt = 0;

  //O(N+M)
  for (int i = 1; i <= N; i++) {
    int tmp = 0;
    for (const auto& node : graph[i]) {
      if (i > node) tmp++;
    }
    if (tmp == 1) cnt++;
  }
  cout << cnt << '\n';
}
