#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int  N;
  string s;
  string t = "";
  cin >> N >> s;
  
  int li=0, ri=N-1;

  // 反転した文字列ともとの文字列を比較して、小さいほうが次にくる文字も小さいので辞書順最小となる
  while (s.length() != 0) {
    string rs(s);
    reverse(rs.begin(), rs.end());
    s = (s <= rs)? s: rs;
    reverse(s.begin(), s.end());
    
    t.push_back(s[rs.length() - 1]);
    s.pop_back();
  }

  cout << t << endl;
}
