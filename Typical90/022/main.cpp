#include <iostream>
#include <numeric>

using namespace std;

// ユークリッドの互除法
long long my_gcd(long long num1, long long num2) {
  while (num2 != 0) {
    long long r = num1 % num2;
    num1 = num2;
    num2 = r;
  }
  return num1;
}

// 全てのピースを立方体にする最大値
// 各辺に対する最大公約数を求める
int main() {
  long long A, B, C;
  cin >> A >> B >> C;

  long long my_gcd3 = my_gcd(A, my_gcd(B, C));
  // long long gcd3 = gcd(A, gcd(B, C));

  cout << A / my_gcd3 + B / my_gcd3 + C / my_gcd3 - 3 << '\n';
  // cout << A / gcd3 + B / gcd3 + C / gcd3 - 3 << '\n';
}
