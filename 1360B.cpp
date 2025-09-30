#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        sort(s.begin(),s.end());
        int ans=1000000;
        for(int i=0;i<n-1;i++){
            int dif=s[i+1]-s[i];
            if(dif<ans){
                ans=dif;
            }
        }
        cout<<ans<<endl;
    }
}
