#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin>>t;
    while (t--) {
        int n; 
        string s;
        cin >> n >> s;
        int first = s.find('B');
        int last  = s.rfind('B');
        cout << (last - first + 1) << "\n";
    }
    return 0;
}
