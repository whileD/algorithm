#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long> v(N);
  for (int i=0; i<N; i++) cin >> v[i];


  // なるべく2分割されたほうがコストは安い44 44 6 2 2 2のとき
  // 100 -> 2 98(100) -> 2 2 96(198) -> ...
  // 100 -> 44 56(100) -> 44 44 12(156) -> ...

  sort(v.begin(), v.end());

  long res = 0;
  while(N > 1) {
    // 板が一番小さい順から２つとる
    int min1 = 0, min2 = 1;
    if (v[min1] > v[min2]) swap(min1, min2);
    for (int i=2; i<N; i++) {
      if (v[i] < v[min1]) {
        min2 = min1;
        min1 = i;
      } else if (v[i] < v[min2]) {
        min2 = i;
      }
    }

    long tmp = v[min1] + v[min2];
    res += tmp;
    if (min1 == N-1) swap(min1, min2);
    v[min1] = tmp;
    v[min2] = v[N-1];
    N--;
  }
  cout << res << endl;
}
