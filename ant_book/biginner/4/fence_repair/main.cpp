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

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i=0; i<N; i++) pq.push(v[i]);

  long res = 0;
  while(pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    res += a + b;
    pq.push(a+b);
  }
  cout << res << endl;
}
