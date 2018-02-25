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
  vector<int> s(N);
  vector<int> t(N);
  for (int i=0; i<N; i++) cin >> s[i] >> t[i];
  vector<pair<int, int>> p(N);
  for (int i=0; i<N; i++) p[i] = make_pair(t[i], s[i]);


  // もっとも仕事が終わるのが早いものを選ぶと
  // 2番目以降が最小の仕事のとり方になる
  // 仕事開始を基準とすると、ドデカ長いのがきたらだめになる
  
  sort(p.begin(), p.end());

  int res = 0;
  int pre = 0;
  for (int i=0; i<N; i++) {
    if (pre < p[i].second) {
      res++;
      pre = p[i].first;
    }
  }
  cout << res << endl;
}
