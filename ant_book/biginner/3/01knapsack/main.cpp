#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N, W;
vector<int> w;
vector<int> v;
vector<vector<int>> table;

int dp(int n, int j) { // n個目,現在jの重さ
  if (n == N) return 0; // 入れるものが無い場合
  if (table[n][j] > 0) return table[n][j];
  if (w[n] > j) return dp(n+1, j); // 入れられない場合
  return memo[n][j] = max(dp(n+1, j), dp(n+1, j-w[n]) + v[n]); // 入れない場合と入れる場合で大きい方を返す
} 

int main(){
  cin >> N >> W;
  w = vector<int>(N);
  v = vector<int>(N);
  table = vector<vector<int>>(N+1, vector<int>(W+1, 0));
  for (int i=0; i<N; i++) cin >> w[i] >> v[i];

  cout << dp(0, W) << endl;
} 
