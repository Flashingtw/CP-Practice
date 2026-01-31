#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> ap(m);
    vector<int> de(n);
    for (int i=0;i<n;i++) {
        cin>>de[i];
    }
    for (int i=0;i<m;i++) {
        cin>>ap[i];
    }
    sort(ap.begin(),ap.end());
    sort(de.begin(),de.end());
    long long ans=0;
    while (!ap.empty()&&!de.empty()) {
        int a = ap.back();
        int d = de.back();
        //make a pair
        if (abs(a-d)<=k) {
            ans++;
            ap.pop_back();
            de.pop_back();
        }
        else if (d>a) {
            de.pop_back();
        }
        else {
            ap.pop_back();
        }
    }
    cout << ans;
}