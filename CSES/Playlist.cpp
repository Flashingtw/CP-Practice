#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for (int i=0;i<n;i++) {
        cin>>v[i];
        mp.insert({v[i],0});
    }
    vector<int> arr;
    int ch=0;
    for (auto &i : mp) {
        i.second = ch++;
    }
    vector<int> cnt(ch,0);
    int left=0,ans=0;
    for (int right=0;right<n;right++) {
        cnt[mp[v[right]]]++;
        while (cnt[mp[v[right]]]>1) {
            cnt[mp[v[left]]]--;
            left++;
        }
        ans = max(ans,right-left+1);
    }
    cout << ans;
}