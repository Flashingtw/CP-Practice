#include <bits/stdc++.h>
using namespace std;
int v[55][55];
struct mo{
    int s,k,t;
};
vector<mo> a;
int m,n;
void go_top(int i,int k){
    if(k==0) return;
    a.push_back({i,k,n+1});
    a.push_back({i,1,n+1});
    a.push_back({n+1,k+1,i});
    int t = v[i][k];
    for(int j=k;j>0;j--){
        v[i][j]=v[i][j-1];
    }
    v[i][0]=t;
}
void swap_d(int i,int j,int d){
    if(d==0){
        a.push_back({i,1,n+1});
        a.push_back({j,1,i});
        a.push_back({n+1,1,j});
        swap(v[i][0],v[j][0]);
        return;
    }
    a.push_back({j,d,n+1});
    a.push_back({i,1,n+1});
    a.push_back({j,1,i});
    a.push_back({n+1,1,j});
    a.push_back({n+1,d,j});
    swap(v[i][0],v[j][d]);
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=0;j--){
            cin>>v[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        //find k to kth stack
        int cnt=0;
        for(int j=0;j<m;j++){
            if(v[k][j]==k) cnt++;
        }
        while(cnt<m){
            int g=-1;
            for(int j=0;j<m;j++){
                if(v[k][j]!=k){
                    g=j;
                    break;
                }
            }
            go_top(k,g);
            int sw_j=-1,sw_d=-1;
            for(int j=k+1;j<=n;j++){
                for(int d=0;d<m;d++){
                    if(v[j][d]==k){
                        sw_j=j;
                        sw_d=d;
                        break;
                    }
                }
                if(sw_j!=-1) break;
            }
            swap_d(k,sw_j,sw_d);
            cnt++;
        }
    }

    cout << a.size() << '\n';
    for(auto [s,k,t]:a){
        cout << s << ' ' << k << ' ' << t << '\n';
    }
}