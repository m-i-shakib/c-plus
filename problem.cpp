#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,m;string a;
        cin>>n>>m>>a;
int A=0, B=0, C=0, D=0, E=0, F=0, G=0;
for (char c :a) {
    if (c=='A') A++;
    else if (c=='B') B++;
    else if (c=='C') C++;
    else if (c=='D') D++;
    else if (c=='E') E++;
    else if (c=='F') F++;
    else if (c=='G') G++;
}
 int need = 0;
        if (A < m) need += (m - A);
        if (B < m) need += (m - B);
        if (C < m) need += (m - C);
        if (D < m) need += (m - D);
        if (E < m) need += (m - E);
        if (F < m) need += (m - F);
        if (G < m) need += (m - G);

        cout << need << endl;
}
}