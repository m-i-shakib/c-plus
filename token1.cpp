#include <bits/stdc++.h>
using namespace std;

// Check if a word is a keyword
bool isKeyword(const string &word) {
    vector<string> keywords = {
        "int", "float", "return", "if", "else", "for", "while", "do",
        "switch", "case", "break", "continue", "void", "double", "char"
    };
    return find(keywords.begin(), keywords.end(), word) != keywords.end();
}

// Check if a string is an integer number
bool isInteger(const string &word) {
    if (word.empty()) return false;
    for (char c : word) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Check if a string is a float number
bool isFloat(const string &word) {
    bool dot = false;
    if (word.empty()) return false;
    for (char c : word) {
        if (c == '.') {
            if (dot) return false;
            dot = true;
        } else if (!isdigit(c)) return false;
    }
    return dot;
}

// Remove comments from code
string removeComments(const string &code) {
    string noComments;
    bool inBlock = false, inLine = false;

    for (size_t i = 0; i < code.size(); i++) {
        if (inBlock) {
            if (code[i] == '*' && i + 1 < code.size() && code[i + 1] == '/') {
                inBlock = false;
                i++; // skip '/'
            }
        } else if (inLine) {
            if (code[i] == '\n') {
                inLine = false;
                noComments += code[i];
            }
        } else {
            if (code[i] == '/' && i + 1 < code.size()) {
                if (code[i + 1] == '/') {
                    inLine = true;
                    i++;
                } else if (code[i + 1] == '*') {
                    inBlock = true;
                    i++;
                } else {
                    noComments += code[i];
                }
            } else {
                noComments += code[i];
            }
        }
    }
    return noComments;
}

int main() {
    string line, code;
    cout << "Enter code (end with # in a new line):\n";
    while (getline(cin, line)) {
        if (line == "#") break;
        code += line + "\n";
    }

    // Remove comments
    code = removeComments(code);

    // Token containers
    vector<string> keywords, identifiers, symbols, operators, integers, floats;

    // Define delimiters
    string delimiters = " ,;(){}[]=+-*/";

    string token;
    for (size_t i = 0; i < code.size(); i++) {
        char c = code[i];
        if (delimiters.find(c) != string::npos) {
            if (!token.empty()) {
                if (isKeyword(token)) keywords.push_back(token);
                else if (isInteger(token)) integers.push_back(token);
                else if (isFloat(token)) floats.push_back(token);
                else identifiers.push_back(token);
                token.clear();
            }
            // Handle symbols/operators
            if (string("(){};,").find(c) != string::npos) {
                symbols.push_back(string(1, c));
            } else if (string("=+-*/").find(c) != string::npos) {
                operators.push_back(string(1, c));
            }
        } else if (!isspace(c)) {
            token += c;
        } else {
            if (!token.empty()) {
                if (isKeyword(token)) keywords.push_back(token);
                else if (isInteger(token)) integers.push_back(token);
                else if (isFloat(token)) floats.push_back(token);
                else identifiers.push_back(token);
                token.clear();
            }
        }
    }

    // Summary
    int totalTokens = keywords.size() + identifiers.size() +
                      symbols.size() + operators.size() +
                      integers.size() + floats.size();

    cout << "\nNo of Token: " << totalTokens << "\n";

    cout << "Keyword: " << keywords.size() << "  ";
    for (auto &k : keywords) cout << k << " ";
    cout << "\n";

    cout << "Identifier: " << identifiers.size() << "  ";
    for (auto &id : identifiers) cout << id << " ";
    cout << "\n";

    cout << "Symbols: " << symbols.size() << "  ";
    for (auto &s : symbols) cout << s << " ";
    cout << "\n";

    cout << "Operator: " << operators.size() << "  ";
    for (auto &op : operators) cout << op << " ";
    cout << "\n";

    cout << "Integer: " << integers.size() << "  ";
    for (auto &in : integers) cout << in << " ";
    cout << "\n";

    cout << "Float: " << floats.size() << "  ";
    for (auto &f : floats) cout << f << " ";
    cout << "\n";

    return 0;
}
/*
//Summation Function
int Sum ( int a, int b )
{
    int s = 0;
    s = a + b;
    return s;
}
#

*/
