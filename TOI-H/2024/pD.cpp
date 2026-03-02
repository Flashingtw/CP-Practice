#include <bits/stdc++.h>
using namespace std;
struct BIT{
    vector<int> tree;
    int sz;
    BIT (int _sz) : sz(_sz),tree(_sz,0){}
    void update(int idx,int val){
        for(;idx<=sz;idx+=idx&-idx){
            tree[idx]+=val;
        }
    }
    int query(int idx){
        int sum=0;
        for(;idx>0;idx-=idx&-idx){
            sum+=tree[idx];
        }
        return sum;
    }
};
struct TREE{
    vector<vector<int>> adj,top;
    vector<int> in,out,p,d;
    int root,n;
    TREE (int sz) : n(sz),adj(sz+1),in(sz+1),out(sz+1),top(sz+1,vector<int>(21)),p(sz+1),d(sz+1) {};
    void add(int u,int v){
        p[v]=u;
        if(u==0){
            root=v;
            return;
        }
        adj[u].push_back(v);
    }
    int cnt=1;
    void dfs_order(int u,int p,int dep){
        in[u]=cnt++;
        d[u]=dep;
        for(int v:adj[u]){
            if(v==p) continue;
            dfs_order(v,u,dep+1);
        }
        out[u]=cnt;
    }
    void make(){
        for(int i=1;i<=n;i++){
            top[i][0]=p[i];
        }
        for(int LOG=1;LOG<=20;LOG++){
            for(int i=1;i<=n;i++){
                top[i][LOG]=top[top[i][LOG-1]][LOG-1];
            }
        }
    }
    int get_k(int u,int k){
        for(int i=20;i>=0;i--){
            if((k>>i)&1){
                u=top[u][i];
                if(u==0) return root;
            }
        }
        return u;
    }
};

long long solve(TREE S,TREE T,int n,int k){
    BIT bit1(n+2),bit2(n+2);
    vector<int> cnt_kf(n+1,0);
    long long ans=0;
    auto dfs = [&](auto self,int u,int p,int d,int valid) -> void{
        int uk = T.get_k(u,k);
        if(T.d[u]>=k){
            int val1 = bit1.query(T.in[uk]);
            int val2 = bit2.query(T.out[uk]-1)-bit2.query(T.in[uk]-1);

            ans += valid-(val1+val2-cnt_kf[uk]);

            bit1.update(T.in[uk],1);
            bit1.update(T.out[uk],-1);
            bit2.update(T.in[uk],1);
            valid++;
            cnt_kf[uk]++;
        }

        for(int v:S.adj[u]){
            if(v==p) continue;
            self(self,v,u,d+1,valid);
        }

        if(T.d[u]>=k) {
            bit1.update(T.in[uk],-1);
            bit1.update(T.out[uk],1);
            bit2.update(T.in[uk],-1);
            valid--;
            cnt_kf[uk]--;
        }
    };
    dfs(dfs,S.root,0,0,0);
    return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    TREE S(n),T(n);
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        S.add(u,i);
    }
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        T.add(u,i);
    }
    S.dfs_order(S.root,0,0);
    T.dfs_order(T.root,0,0);
    S.make();
    T.make();

    cout << solve(S,T,n,k)+solve(T,S,n,k);
}
