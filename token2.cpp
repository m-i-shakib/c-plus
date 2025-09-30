#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1) Read input code (end with a line that has only #)
    cout << "Enter code (end with # in a new line):\n";
    string line, code;
    while (getline(cin, line)) { if (line == "#") break; code += line + "\n"; }

    // 2) Remove // and /* */ comments (simple, not perfect for strings)
    {
        string out; bool inBlock = false, inLine = false;
        for (size_t i = 0; i < code.size(); ++i) {
            if (inBlock) {
                if (code[i] == '*' && i + 1 < code.size() && code[i + 1] == '/') { inBlock = false; ++i; }
            } else if (inLine) {
                if (code[i] == '\n') { inLine = false; out += '\n'; }
            } else {
                if (code[i] == '/' && i + 1 < code.size()) {
                    if (code[i + 1] == '/') { inLine = true; ++i; continue; }
                    if (code[i + 1] == '*') { inBlock = true; ++i; continue; }
                }
                out += code[i];
            }
        }
        code = move(out);
    }

    // 3) Small helpers
    const unordered_set<string> kw = {
        "int","float","return","if","else","for","while","do",
        "switch","case","break","continue","void","double","char"
    };
    auto isInt   = [](const string& s){ if(s.empty()) return false; for(char c:s) if(!isdigit((unsigned char)c)) return false; return true; };
    auto isFloat = [](const string& s){ if(s.empty()) return false; bool dot=false; for(char c:s){ if(c=='.'){ if(dot) return false; dot=true; } else if(!isdigit((unsigned char)c)) return false; } return dot; };

    auto isSymbol   = [](char c){ return string("(){};,").find(c) != string::npos; };
    auto isOperator = [](char c){ return string("=+-*/").find(c) != string::npos; };
    auto isDelim    = [&](char c){ return isspace((unsigned char)c) || isSymbol(c) || isOperator(c); };

    // 4) Tokenize by scanning characters
    vector<string> keywords, identifiers, symbols, operators_, integers, floats_;
    string tok;
    auto flushToken = [&](){
        if (tok.empty()) return;
        if (kw.count(tok)) keywords.push_back(tok);
        else if (isInt(tok)) integers.push_back(tok);
        else if (isFloat(tok)) floats_.push_back(tok);
        else identifiers.push_back(tok);
        tok.clear();
    };

    for (size_t i = 0; i < code.size(); ++i) {
        char c = code[i];
        if (isDelim(c)) {
            flushToken();
            if (isSymbol(c))   symbols.push_back(string(1, c));
            else if (isOperator(c)) operators_.push_back(string(1, c));
        } else {
            tok += c;
        }
    }
    flushToken();

    // 5) Print summary
    int total = (int)(keywords.size() + identifiers.size() + symbols.size() +
                      operators_.size() + integers.size() + floats_.size());

    cout << "\nNo of Token: " << total << "\n";

    auto printVec = [](const string& name, const vector<string>& v){
        cout << name << ": " << v.size() << "  ";
        for (auto& x : v) cout << x << " ";
        cout << "\n";
    };

    printVec("Keyword",    keywords);
    printVec("Identifier", identifiers);
    printVec("Symbols",    symbols);
    printVec("Operator",   operators_);
    printVec("Integer",    integers);
    printVec("Float",      floats_);

    return 0;
}

