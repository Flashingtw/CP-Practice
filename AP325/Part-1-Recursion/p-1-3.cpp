#include <iostream>
using namespace std;
long long p[50010];
int n;
int l;
long long total_cost=0;
long long cut(int left,int r) {
    if (r-left<=1) return 0; // if r = 2 l = 1 no point can be cutted
    total_cost += p[r]-p[left];
    long long k = (p[left]+p[r])/2;
    int mid = lower_bound(p+left,p+r,k)-p;
    if (p[mid-1]-p[left]>=p[r]-p[mid]) mid--; //if 上一個切割點->左邊的距離 >= 原本的切割點->右邊的距離 用左邊的
    return cut(left,mid) + cut(mid,r);
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>l;
    p[0]=0;
    p[n+1]=l;
    for (int i=1;i<=n;i++)cin>>p[i];
    cut(0,n+1);
    cout << total_cost;
}