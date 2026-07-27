#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int m,n,k;
    set<int> a;
    cin>>m>>n>>k;
    for (int i=0;i<m;i++) {
        int t;
        cin>>t;
        a.insert(k-t);
    }
    int ans=0;
    for (int i=0;i<n;i++) {
        int t;
        cin>>t;
        if (a.count(t)) {
            ans++;
        }
    }
    cout << ans;
}