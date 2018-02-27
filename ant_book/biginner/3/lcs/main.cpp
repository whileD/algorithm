#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for (int i=0; i<n; i++) {
    for (int k=0; k<m; k++) {
      if (a[i] == b[k]) dp[i+1][k+1] = dp[i][k] + 1;
      else dp[i+1][k+1] = max(dp[i+1][k], dp[i][k+1]);
    }
  }
  cout << dp[n][m] << endl;
}
