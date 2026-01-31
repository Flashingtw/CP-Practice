#include <bits/stdc++.h>
using namespace std;
struct homework {
    int t,dl;
};
bool cmp(homework h1,homework h2) {
    return h1.dl<h2.dl;
}
int main() {
    int T;
    cin>>T;
    for (int i=0;i<T;i++) {
        int n;
        cin>>n;
        vector<homework> v(n);
        for (int i=0;i<n;i++) {
            cin>>v[i].t;
        }
        for (int i=0;i<n;i++) {
            cin>>v[i].dl;
        }
        sort(v.begin(),v.end(),[&](auto& h1, auto &h2){return h1.dl<h2.dl;});
        bool s=true;
        long long t = 0;
        for (int i=0;i<n;i++) {
            t+=v[i].t;
            s = v[i].dl>=t;
            if (!s) break;
        }
        cout << (s?"yes":"no") << "\n";
    }
}