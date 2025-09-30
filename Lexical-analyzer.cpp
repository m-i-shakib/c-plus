#include <bits/stdc++.h>
using namespace std;

bool isKeyword(string s)
{
    set<string> keywords =
    {
        "alignas","alignof","and","and_eq","asm","auto","bitand","bitor","bool","break",
        "case","catch","char","char8_t","char16_t","char32_t","class","compl","concept",
        "const","consteval","constexpr","const_cast","continue","co_await","co_return",
        "co_yield","decltype","default","delete","do","double","dynamic_cast","else","enum",
        "explicit","export","extern","false","float","for","friend","goto","if","inline",
        "int","long","mutable","namespace","new","noexcept","not","not_eq","nullptr",
        "operator","or","or_eq","private","protected","public","register","reinterpret_cast",
        "requires","return","short","signed","sizeof","static","static_assert","static_cast",
        "struct","switch","template","this","thread_local","throw","true","try","typedef",
        "typeid","typename","union","unsigned","using","virtual","void","volatile",
        "wchar_t","while","xor","xor_eq"
    };
    return keywords.count(s);
}

bool isInteger(string s)
{
    if(s.empty())
    {
        return false;
    }

    for (char c : s)
    {
        if(!isdigit(c))
            return false;
    }
    return true;
}

bool isFloat(string s)
{
    int dot_count=count(s.begin(),s.end(),'.');
    if(dot_count>1)
    {
        return false;
    }
    int pos=s.find('.');
    if(pos==s.size()-1 || pos==-1)
    {
        return false;
    }
    if(s[0]=='.' && pos!=s.size()-1)
    {
        return true;
    }
    for(int i=0; i<s.size(); i++)
    {
        if(i==pos)
            continue;
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}
bool isIdentifier(string s)
{
    if(s.empty() || isdigit(s[0]))
    {
        return false;
    }
    for(char c : s)
    {
        if(!isalnum(c) && c != '_' && c != '$')
            return false;
    }
    return true;
}

bool isOperator(string s)
{
    set<string> operators =
    {
        "+","-","*","/","%","=","+=","-=","*=","/=","%=",
        "++","--","==","!=","<",">","<=",">=","&&","||","!",
        "&","|","^","~","<<","<<=",">>"," >>=","->",".","::","?"
    };
    return operators.count(s);
}

bool isSymbol(char c)
{
    set<char>symbols =
    {
        '_','$',';','(',')','{','}','[',']',','
    };
    return symbols.count(c);
}

vector<string>tokenize(const string &line)
{
    vector<string>tokens;
    string current;
    for(int i = 0; i < line.size(); i++)
    {
        char c = line[i];

        if (isspace(c))
        {
            if (!current.empty())
            {
                tokens.push_back(current);
                current.clear();
            }
            continue;
        }

        string twoChar = "", threeChar = "";
        if(i + 1 < line.size())
        {
            twoChar += c;
            twoChar += line[i+1];
        }
        if(i + 2 < line.size())
        {
            threeChar += c;
            threeChar += line[i+1];
            threeChar += line[i+2];
        }

        if(isOperator(threeChar))
        {
            if(!current.empty())
            {
                tokens.push_back(current);
                current.clear();
            }
            tokens.push_back(threeChar);
            i += 2;
            continue;
        }
        if(isOperator(twoChar))
        {
            if(!current.empty())
            {
                tokens.push_back(current);
                current.clear();
            }
            tokens.push_back(twoChar);
            i += 1;
            continue;
        }

        if(isOperator(string(1,c)) || isSymbol(c))
        {
            if(c == '.' && !current.empty() && all_of(current.begin(), current.end(), ::isdigit))
            {
                current += c;
                continue;
            }

            if(!current.empty())
            {
                tokens.push_back(current);
                current.clear();
            }
            tokens.push_back(string(1,c));
            continue;
        }
        current += c;
    }
    if (!current.empty())
    {
        tokens.push_back(current);
    }
    return tokens;
}

int main()
{
    string filename;
    cout << "Enter the input file: ";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string line;
    while(getline(inFile, line))
    {
        vector<string> tokens = tokenize(line);
        for (auto &token : tokens)
        {
            if (isKeyword(token))
                cout << token << " -> Keyword" << endl;
            else if (isInteger(token))
                cout << token << " -> Integer" << endl;
            else if (isFloat(token))
                cout << token << " -> Float" << endl;
            else if (isIdentifier(token))
                cout << token << " -> Identifier" << endl;
            else if (isOperator(token))
                cout << token << " -> Operator" << endl;
            else if (token.size() == 1 && isSymbol(token[0]))
                cout << token << " -> Symbol" << endl;
            else
                cout << token << " -> Invalid Token" << endl;
        }
    }

    inFile.close();
    return 0;
}
