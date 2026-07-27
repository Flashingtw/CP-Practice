#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int n,m;
    cin>>m>>n;
    map<int,int> mp;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        mp[v[i]]=0;
    }
    int n_color=0;
    for (auto &i : mp) i.second=n_color++;

    vector<int> cnt(200010,0);
    int left=0,count=0;
    for (int i=0;i<n;i++) {
        int color = mp[v[i]];
        cnt[color]++;

        while (cnt[color]>1) {
            cnt[mp[v[left]]]--;
            left++;
        }
        if (i-left+1==m) count++;
    }
    cout << count;
}