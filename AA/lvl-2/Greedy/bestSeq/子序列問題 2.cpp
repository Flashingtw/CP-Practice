#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e6+5;
int nxt[N][2];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    nxt[n][0]=nxt[n][1]=n;
    for(int i=n-1;i>=0;i--){
        nxt[i][0] = nxt[i+1][0];
        nxt[i][1] = nxt[i+1][1];
        nxt[i][s[i]-'0'] = i;
    }
    while(q--){
        string a;
        cin>>a;
        int pos=0;
        for(char c:a){
            int j = nxt[pos][c-'0'];
            if(j==n){
                pos=-1;
                break;
            }
            pos = j+1;
        }
        cout << pos << '\n';
    }
}