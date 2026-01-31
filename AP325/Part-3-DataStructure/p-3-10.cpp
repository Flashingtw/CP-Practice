#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for (int i=0;i<n;i++) {
        cin>>v[i];
        mp[v[i]]=0;
    }
    int n_color=0;
    for (auto &i : mp) i.second = n_color++;
    int cnt[200010];
    int m=0;
    int left=0,right=0,w_color=0,shortest =n;
    while (right<n) {
        int color = mp[v[right]];
        cnt[color] ++;
        if (cnt[color]==1) w_color++;
        right++;
        while (1) {
            color = mp[v[left]];
            if (cnt[color]==1) break;
            left++;
            cnt[color]--;
        }
        if (w_color==n_color) shortest = min(shortest,right-left);
    }
    cout << shortest;
}