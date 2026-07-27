#include <bits/stdc++.h>
using namespace std;
#define N 510
int m,n,k;
int max_area=0,cnt=0;
int parents[N*N],siz[N*N];

int find(int x) {
    if (parents[x]==x) return x;
    return parents[x] = find(parents[x]);
}

void merge(int x,int y) {
    int a = find(x);
    int b = find(y);
    if (a==b) return;
    parents[a] = b;
    siz[b] += siz[a];
    cnt--;
    max_area = max(max_area,siz[b]);
}

int main() {
    cin>>m>>n>>k;
    m+=2,n+=2;
    int di[4] = {-1,n,1,-n};
    int s[N*N];
    for (int i=0;i<m;i++) for (int j=0;j<n;j++) s[i*n+j] =0;
    for (int i=1;i<m-1;i++) for (int j=1;j<n-1;j++) cin>>s[i*n+j];
    for (int i=0;i<n*m;i++){
        parents[i] = i;
        siz[i] = 1;
    }
    for (int i=0;i<m;i++) for (int j=0;j<n;j++) {
        if (s[i*n+j]==1) {
            cnt++;
            max_area = max(max_area,1);
            if (s[i*n+j-1]==1) merge(i*n+j,i*n+j-1);
            if (s[i*n+j-n]==1) merge(i*n+j,i*n+j-n);
        }
    }
    //start k
    long long ans_size=max_area,ans_cnt=cnt;
    for (int i=0;i<k;i++) {
        int r,c;
        cin>>r>>c;
        int pos = r*n+c;
        if (s[pos]==0) {
            s[pos] = 1;
            cnt++;
            max_area = max(max_area, 1);
            for (int dir=0;dir<4;dir++) {
                if (s[pos+di[dir]]==1) merge(pos,pos+di[dir]);
            }
        }
        ans_size+=max_area,ans_cnt+=cnt;
    }
    cout << ans_size << "\n" << ans_cnt;
}