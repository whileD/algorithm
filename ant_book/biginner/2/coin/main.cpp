#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  vector<int> c(6);
  vector<int> v = {1, 5, 10, 50, 100, 500};
  for (int i=0; i<6; i++) cin >> c[i];
  int A;
  cin >> A;

  int res = 0;
  for (int i=5; i>=0; i--) {
    int t = min(A/v[i], c[i]);
    A -= t*v[i];
    res += t;
  }
  cout << res << endl;
}
