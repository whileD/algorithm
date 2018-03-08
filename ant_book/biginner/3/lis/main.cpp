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
  vector<int> v(N);
  for(int i=0; i<N; i++) cin >> v[i];

  vector<int> dp(N+1, 0);
  int res = 1;
  for (int i=0; i<N; i++) {
    dp[i] = 1;
    for (int k=0; k<i; k++) {
      if (v[k] < v[i]) 
        dp[i] = max(dp[i], dp[k] + 1);
    }
    res = max(res, dp[i]);
  }

  cout << res << endl;
}
