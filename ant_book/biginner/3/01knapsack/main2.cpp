#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// 漸化式をとく実装
int main(){
  int N, W;
  cin >> N >> W;
  vector<int> w(N);
  vector<int> v(N);
  for (int i=0; i<N; i++) cin >> w[i] >> v[i];

  vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

  // i番目までのものを重さの総和がk以下になるように選んだときの価値の最大値
  for (int i=0; i<N; i++) { 
    for (int k=0; k<=W; k++) {
      if (k < w[i]) {
        dp[i+1][k] = dp[i][k];
      } else {
        dp[i+1][k] = max(dp[i][k], dp[i][k-w[i]] + v[i]);
      }
    }
  }
  cout << dp[N][W] << endl;
}
