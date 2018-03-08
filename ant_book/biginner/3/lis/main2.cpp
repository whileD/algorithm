#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i=0; i<N; i++) cin >> v[i];

  vector<int> dp(N+1, INT_MAX);
  for (int i=0; i<N; i++) {
    auto it = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
    dp[it] = v[i];
    for (auto b: dp) {
      cout << b << " ";
    }
    cout << endl;
  }

  cout << (int)(lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin()) << endl;
}
