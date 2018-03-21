#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class UnionFindTree {
  private: 
    vector<int> v; // parent
    vector<int> rank; // 深さ
  public:
    UnionFindTree(int max) {
      v = vector<int>(max);
      rank = vector<int>(max, 1);
      for (int i=0; i<max; i++) v[i] = i;
    }

    int find(int x) {
      if(v[x] == x) return x;
      else return v[x] = find(v[x]);
    }

    // xとyの木併合
    void unite(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) return;


      if (rank[x] < rank[y]) v[x] = y;
      else {
        v[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
      }
    }

    bool same(int x, int y) {
      return find(x) == find(y);
    }
};

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> type(K);
  vector<int> X(K);
  vector<int> Y(K);
  for (int i=0; i<K; i++) cin >> type[i] >> X[i] >> Y[i];

  int res = 0;
  UnionFindTree ut(N*3);

  for (int i=0; i<K; i++) {
    int t = type[i];
    int x = X[i] - 1, y = Y[i] - 1;
    if (x < 0 || N <= x || y < 0 || N <= y) {
      res++;
      continue;
    }

    if (t == 1) {
      if (ut.same(x, y + N) || ut.same(x, y + N *2)) res++; // x,yは同じグループ,じゃなかったら
      else {
        ut.unite(x, y);
        ut.unite(x + N, y + N);
        ut.unite(x + N*2, y + N*2);
      }
    } else {
      if (ut.same(x, y) || ut.same(x, y + N*2)) res++;
      else {
        ut.unite(x, y+N);
        ut.unite(x+N, y+N*2);
        ut.unite(x+N*2, y);
      }
    }
  }
  cout << res << endl;
}
