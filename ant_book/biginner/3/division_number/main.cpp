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

  vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); 
  dp[0][0] = 1;
  for (int i=1; i<=m; i++) {
    for (int j=0; j<=n; j++) {
      if (i > j) dp[i][j] = dp[i-1][j];
      else dp[i][j] = (dp[i][j-i] + dp[i-1][j]) % M;
    }
  }
  cout << dp[m][n] << endl;
}
