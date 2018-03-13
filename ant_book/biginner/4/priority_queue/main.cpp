#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N, L, P;
  cin >> N >> L >> P;
  vector<int> a(N);
  vector<int> b(N);
  for (int i=0; i<N; i++) cin >> a[i] >> b[i];
  a.push_back(L);
  b.push_back(0);

  int res = 0, pos = 0;

  priority_queue<int> pq;

  for (int i=0; i<N; i++) {
    int diff = a[i] - pos;

    while(P-diff < 0) {
      if (pq.empty()) {
        cout << -1 << endl;
        return 0;
      }

      P += pq.top(); pq.pop();
      res++;
    }

    P -= diff;
    pos = a[i];
    pq.push(b[i]);
  }

  cout << res << endl;
}
