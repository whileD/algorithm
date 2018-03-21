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
