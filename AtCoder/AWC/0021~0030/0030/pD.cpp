#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int nxt[N];
int ans[N];
int vis[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>nxt[i];
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            vector<int> v;
            int nx=i;
            while(vis[nx]==0){
                v.push_back(nx);
                vis[nx]=1;
                nx = nxt[nx];
            }
            int fin=0;
            if(vis[nx]==1){
                fin=1;
                for(int cur=nxt[nx];cur!=nx;cur=nxt[cur]){
                    fin++;
                }
            }
            else if (vis[nx]==2){
                fin = ans[nx];
            }
            for(int a:v){
                vis[a]=2;
                ans[a] = fin;
            }
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << ' ';
}