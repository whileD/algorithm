#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int n, m, M;
  cin >> n >> m >> M;
  vector<long> v(n);
  for(int i=0; i<n; i++) cin >> v[i];
  
  // dp[i+1][j] = iまでの品物からj個選ぶ組み合わせの総数
  // i番目までの品物からj個選ぶためには、i-1番目までの品物からj-k個選んでi番目の品物をk個加えたらいい
  // dp[i+1][j] = (k=0)シグマ(min(j, a[i]))dp[i][j-k] = (k=0)シグマ(min(j-1, a[i]))(dp[i][j-1-k]) + dp[i][j] - dp[i][j-1-a_i]? 
  //
  // dp[i+1][j] = dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a_i] 
  // 最後のはaの数が足りなかった場合の差分を引いてる
  // 微妙によくわからん
  vector<vector<long>> dp(n+1, vector<long>(m+1, 0));

  for (int i=0; i<=n; i++) {
    dp[i][0] = 1;
  }
  for (int i=0; i<n; i++) {
    for (int j=1; j<=m; j++) {
      if (j-1-v[i] >= 0) {
        // Mを足してるのは-にしないため
        dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-v[i]] + M ) % M;
      } else {
        dp[i+1][j] = (dp[i+1][j-1] + dp[i][j]) % M;
      }
    } 
  }
  cout << dp[n][m] << endl;
} 
