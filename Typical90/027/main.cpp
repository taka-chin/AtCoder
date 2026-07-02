#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;

  set<string> id;

  for (int i = 1; i <= N; i++) {
    string name;
    cin >> name;
    if (id.insert(name).second) cout << i << '\n';
  }
}
