#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<char> pas(n,'#');
    for(int i=0;i<m;i++){
        int p;
        char c;
        cin>>p>>c;
        p--;
        pas[p]=c;
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(pas[i]!='#'&&s[i]==pas[i]){
                cnt++;
            }
        }
        cout << (cnt==m?"Yes":"No") << '\n';
    }
}