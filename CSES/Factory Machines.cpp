#include <bits/stdc++.h>
using namespace std;
int n,need;
vector<int> v;
bool check(long long k) {
    long long sum=0;
    for (long long i : v) {
        sum+= k/i;
        if (sum >= need) return true;
    }
    return sum>=need;
}
int main() {
    cin>>n>>need;
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        v.push_back(num);
    }
    long long l=0,r=1e18,ans=0;
    while (l<=r) {
        long long mid = (l+r)/2;
        if (check(mid)) {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    cout << ans;
}