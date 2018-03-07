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
  int N, W;
  cin >> N >> W;
  vector<int> w(N);
  vector<int> v(N);
  for (int i=0; i<N; i++) cin >> w[i] >> v[i];

  int MAX_V = 0;
  int MAX_N = 100;
  for (int i=0; i<v.size(); i++)
    if (MAX_V < v[i]) MAX_V = v[i];

  
  vector<vector<int>> dp(MAX_N+1, vector<int>(MAX_N*MAX_V + 1, 0));
  for (int i=0; i<MAX_N*MAX_V+1; i++) dp[0][i] = 999999999;
  dp[0][0] = 0;

  // 重さが最小になるようにとる
  for (int i=0; i<N; i++) { 
    for (int k=0; k < MAX_N*MAX_V + 1; k++) {
      if (k < v[i]) dp[i+1][k] = dp[i][k];
      else dp[i+1][k] = min(dp[i][k], dp[i][k-v[i]] + w[i]);
    }
  }

  vector<int> r;
  for (int i=0; i<N; i++)
    for (int k=0; k<=MAX_N*MAX_V; k++) 
      if (W >= dp[i][k]) r.push_back(k);

  sort(r.begin(), r.end(), greater<int>());
  cout << r[0] << endl;
}
