#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

template<typename T> class HeapTree {
  public:
    vector<T> v;
    HeapTree() { v = vector<T>(); }
    HeapTree(vector<T> vec) { for (long i=0; i<vec.size(); i++) this->push(vec[i]); }

    void push(T x) {
      this->v.push_back(x);
      long i = (long)this->v.size()-1;

      while(i > 0) {
        int p = (i - 1) / 2;
        if (this->v[p] <= x) break;

        swap(this->v[i], this->v[p]);
        i = p;
      }
    }

    void display() {
      for (auto a: v) {
        cout << a << endl;
      }
    }


    T pop(){
      T ret = this->v[0];
      this->v[0] = this->v[v.size() - 1];
      this->v.pop_back();

      long i = 0;
      while(i * 2 + 1 < this->v.size()) {
        long a = i * 2 + 1;
        long b = i * 2 + 2;
        if (b < v.size() && this->v[b] < this->v[a]) a = b;
        if (this->v[a] >= this->v[i]) break;

        swap(this->v[a], this->v[i]);
        i = a;
      }
      return ret;
    }
};

int main(){
  int N;
  cin >> N;
  HeapTree<int> hp;
  int tmp;
  for (int i=0; i<N; i++) {
    cin >> tmp;
    hp.push(tmp);
  }
  for (int i=0; i<N; i++) {
    cout << hp.pop() << endl;
  }
}
