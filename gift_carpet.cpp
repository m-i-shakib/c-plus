#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string grid[25];
    for (int i = 0; i < n; i++)
      cin >> grid[i];
    string name = "vika";
    int p = 0;
    for (int col = 0; col < m; col++) {
      for (int row = 0; row < n; row++) {
        if (grid[row][col] == name[p]) {
          p++;
          break;
        }
      }
      if (p == 4)
        break;
    }
    cout << (p == 4 ? "YES" : "NO") << "\n";
  }
}
