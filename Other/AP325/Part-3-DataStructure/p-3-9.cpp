#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,l;
    cin>>n>>l;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin>>v[i];
    vector<int> cnt(200010,0);
    int n_color=0;
    for (int i=0;i<l;i++) {
        int color = v[i];
        cnt[color]++;
        if (cnt[color]==1) n_color++;
    }
    int ans=n_color;
    for (int left=0,right=l;right<n;left++,right++) {
        int color = v[right];
        cnt[color]++;
        if (cnt[color]==1) n_color++;

        color = v[left];
        cnt[color]--;
        if (cnt[color]==0) n_color--;

        ans = max(ans,n_color);
    }
    cout << ans;
}