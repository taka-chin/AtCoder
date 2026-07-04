#include <iostream>
#include <deque>

using namespace std;

int main()
{
  int Q;
  cin >> Q;
  deque<long long> cards;

  for(int i=0;i<Q;i++)
  {
    int t;
    long long x;
    cin >> t >> x;
    if(t == 1)
      cards.push_front(x);
    else if(t == 2)
      cards.push_back(x);
    else
      cout << cards[x-1] << '\n';
  }
}
