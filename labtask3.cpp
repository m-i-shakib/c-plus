#include <bits/stdc++.h>
using namespace std;
bool isValidIdentifier(string str) {
    if (str.length() == 0) {
        return false;
    }
    if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || (str[0] == '_')) {
        for (int i = 1; i < str.length(); i++) {
            if (!((str[i] >= 'a' && str[i] <= 'z') || 
                  (str[i] >= 'A' && str[i] <= 'Z') || 
                  (str[i] >= '0' && str[i] <= '9') || 
                  (str[i] == '_'))) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if(isValidIdentifier(input)) {
            cout << "Valid Identifier: " << input << endl;
        } else {
            cout << "Invalid Identifier: " << input << endl;
        }
    }
    return 0;
}