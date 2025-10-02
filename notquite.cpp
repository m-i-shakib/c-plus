#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;cin >> t;
  while (t--) {
    char g[3][3];
    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        cin >> g[i][j];
    }
}
    for (int i = 0; i < 3; i++) {
      int counta = 0, countb = 0, countc = 0, countq = 0;

      for (int j = 0; j < 3; j++) {
        if (g[i][j] == 'A')counta++;
        if (g[i][j] == 'B')countb++;
        if (g[i][j] == 'C')countc++;
        if (g[i][j] == '?')countq = 1;
      }
      if (countq) {
        if (counta == 0)cout << "A\n";
        else if (countb == 0)cout << "B\n";
        else cout << "C\n";
      }
    }
  }
}