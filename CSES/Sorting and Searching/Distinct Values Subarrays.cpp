#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for (int i=0;i<n;i++) {
        cin>>v[i];
        mp.insert({v[i],0});
    }
    int count_a=0;
    for (auto &i : mp) i.second = count_a++;
    vector<int> cnt(count_a);
    int left=0;
    long long ans = 0;
    for (int right=0;right<n;right++) {
        int right_n = mp[v[right]];
        cnt[right_n]++;
        while (cnt[right_n]>1) {
            cnt[mp[v[left]]]--;
            left++;
        }
        ans+=right-left+1;
    }
    cout << ans;
}