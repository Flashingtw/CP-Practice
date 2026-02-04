#include <bits/stdc++.h>
using namespace std;
#define N 100005
vector<int> child[N];
int leng[N],dis[N],step[N];
int max_step=0,max_leng=0;
//dfs
void dfs(int x) {
    for (int i : child[x]) {
        dis[i] = dis[x]+leng[i];
        max_leng = max(max_leng,dis[i]);
        step[i] = step[x]+1;
        max_step = max(max_step,step[i]);
        dfs(i);
    }
}

int main() {
    int n;
    cin>>n;
    //a是i的parents
    for (int i=1;i<n;i++) {
        int a,w;
        cin>>a>>w;
        leng[i] = w;
        child[a].push_back(i);
    }
    dis[0] =0;
    step[0] = 0;
    dfs(0);
    cout << max_leng << "\n" << max_step;
}