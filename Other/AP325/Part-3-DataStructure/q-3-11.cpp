#include <iostream>
#include <map>
#include <vector>
using namespace std;
int cnt[200010];
int main() {
    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i=1;i<=n;i++) cin>>v[i];
    int left=1;
    int longest=0;
    for (int i=1;i<=n;i++) {
        int color = v[i];
        cnt[color]++;

        while (cnt[color]>1) {
            cnt[v[left]]--;
            left++;
        }

        longest = max(longest,i-left+1);
    }
    cout << longest;
}