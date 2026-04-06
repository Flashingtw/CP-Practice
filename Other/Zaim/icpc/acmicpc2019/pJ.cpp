#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll grid[505][55];
ll prefix[505][55];

struct ev{
    ll t,type;
    bool operator<(ev o){
        if (t!=o.t) return t<o.t;
        return type>o.type;
    }
};

int main(){
    int n,h;
    cin>>n>>h;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=h;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        sort(grid[i]+1,grid[i]+h+1);
        for(int j=1;j<=h;j++){
            prefix[i][j] = prefix[i][j-1]+grid[i][j]; 
        }
    }
    for(int i=1;i<=n;i++){
        vector<ev> eve;
        for(int k=1;k<=n;k++){
            if(k==i) continue;
            vector<ll> sc;
            sc.push_back(1);
            sc.push_back(2e18);
            for(int j=1;j<=h;j++){
                sc.push_back(grid[i][j]);
                sc.push_back(grid[k][j]);
            }
            sort(sc.begin(),sc.end());
            sc.erase(unique(sc.begin(),sc.end()),sc.end());
            int m = sc.size();
            for(int s=0;s<m-1;s++){
                ll lb = sc[s];
                ll rb = sc[s+1];
                int cnti = upper_bound(grid[i]+1,grid[i]+h+1,lb)-(grid[i]+1);
                ll ai = h-cnti;
                ll bi = prefix[i][cnti];

                int cntk = upper_bound(grid[k]+1,grid[k]+h+1,lb)-(grid[k]+1);
                ll ak = h-cntk;
                ll bk = prefix[k][cntk];

                ll da = ak-ai;
                ll db = bi-bk;
                ll curl = lb,curr = rb-1;
                if(da==0){
                    if(db<0){
                        curl =1;
                        curr =0;
                    }
                }
                if(da>0){
                    ll c = db/da;
                    if(db<0&&db%da!=0) c--;
                    curr = min(curr,c);
                }
                if(da<0){
                    ll c = (-db)/(-da);
                    if ((-db)>0&&(-db)%(-da)!=0) c++;
                    curl = max(curl,c);
                }
                if(curl<=curr){
                    eve.push_back({curl,1});
                    eve.push_back({curr+1,-1});
                }
            }
        }
        sort(eve.begin(),eve.end());
        int cur=1,mn=n;
        if(eve.empty()||eve[0].t>1){
            mn=1;
        }
        int w = eve.size();
        for (int c=0;c<w;) {
            if (eve[c].t >= 2e18) break; 
            int nxt = c;
            while (nxt<w&&eve[nxt].t==eve[c].t) {
                cur += eve[nxt].type;
                nxt++;
            }
            mn = min(mn, cur);
            c = nxt;
        }
        cout << mn << '\n';
    }
}