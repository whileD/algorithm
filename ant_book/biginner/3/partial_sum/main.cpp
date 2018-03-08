#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  vector<int> m(N);
  for (int i=0; i<N; i++) cin >> a[i] >> m[i];

  vector<int> dp(K+1, -1);
  dp[0] = 0;
  for (int i=0; i<N; i++) {
    for (int k=0; k<=K; k++) {
      if (dp[k] >= 0) dp[k] = m[i];
      else if (k < a[i] || dp[k- a[i]] <= 0) dp[k] = -1;
      else dp[k] = dp[k - a[i]] - 1;
    }
  }

  cout << ((dp[K] >= 0)? "Yes": "No") << endl;
}
