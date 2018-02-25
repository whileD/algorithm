#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N, R;
  cin >> N >> R;
  vector<int> x(N);
  for (int i=0; i<N; i++) cin >> x[i];
  sort (x.begin(), x.end());

  int last = x[0];
  int res = 0;
  int i = 0;
  int s = 0, p = 0;
  while(i<N) {
    // 現在から+R超える点まですすめる(ある点を0としたときに-Rにあたる)
    // x[i++] <- (0 -> 1)インクリメントの挙動忘れてた
    s = x[i++];
    while(i<N && x[i] <= s + R) i++;
    
    // 現在からさらに+Rを超える点まですすめる(+R)
    p = x[i - 1];
    while(i<N && x[i] <= p + R) i++;
    res++;
  }
  cout << res << endl;
}
