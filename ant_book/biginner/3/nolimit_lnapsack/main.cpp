#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N, W;
  cin >> N >> W;
  vector<int> w(N);
  vector<int> v(N);
  for (int i=0; i<N; i++) cin >> w[i] >> v[i];

  vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

  for (int i=0; i<N; i++) {
    for (int k=0; k<=W; k++) {
      if (k < w[i]) {
        dp[i+1][k] = dp[i][k];
      } else {
        dp[i+1][k] = max(dp[i][k], dp[i+1][k-w[i]] + v[i]); // dp[i+1][k-w[i]] で次の行のw[i]倍のものをもってきてる
      }
    }
  }

  cout << dp[N][W] << endl;
}
