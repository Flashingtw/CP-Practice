#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int g[15][26];
int main(){
    int n;
    cin>>n;
    vector<pii> A(n);
    for(int i=0;i<n;i++) cin>>A[i].first>>A[i].second;
    int m;
    cin>>m;
    vector<string> B(m);
    for(int i=0;i<m;i++) cin>>B[i];
    for(string &s:B){
        int sz = s.length();
        for(int i=0;i<n;i++){
            auto [a,b] = A[i];
            if(a==sz){
                g[i][s[b-1]-'a']++;
            }
        }
    }
    for(int i=0;i<m;i++){
        int sz = B[i].length();
        if(sz<n) {
            cout << "No\n";
            continue;
        }
        bool a=1;
        for(int j=0;j<sz;j++){
            if(!g[j][B[i][j]-'a']){
                a=0;
                break;
            }
        }
        if(a) cout << "Yes\n";
        else cout << "No\n";
    }
}