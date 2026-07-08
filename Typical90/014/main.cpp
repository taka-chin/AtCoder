#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> homes(N);
  vector<int> schools(N);

  for (auto& home : homes) cin >> home;

  for (auto& school : schools) cin >> school;

  sort(homes.begin(), homes.end());
  sort(schools.begin(), schools.end());

  long long total_distance = 0;
  for (int i = 0; i < N; i++) total_distance += abs(homes[i] - schools[i]);

  cout << total_distance << '\n';
}
