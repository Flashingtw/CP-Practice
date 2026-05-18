#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5+5;
int f[N],b[N];

int main(){
    int n,q;
    cin>>n>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            b[x] = y;
            f[y] = x;
        }
        if(t==2){
            int x,y;
            cin>>x>>y;
            b[x] = 0;
            f[y] = 0; 
        }
        if(t==3){
            int x;
            cin>>x;
            int cur = x;
            while(f[cur]!=0){
                cur = f[cur];
            }
            vector<int> ans;
            while(cur){
                ans.push_back(cur);
                cur = b[cur];
            }
            cout << ans.size() << ' ';
            for(int i:ans) cout << i << ' ';
            cout << '\n';
        }
    }
}