#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct line {
    long long a;
    long long b;
    long long eval(long long x) { return a * x + b; }
};

bool cmp(line a, line b){
    return a.a<b.a;
}

bool is_useless(line l1, line l2, line l3) {
    return (double)(l2.b - l1.b) * (l2.a - l3.a) >= (double)(l3.b - l2.b) * (l1.a - l2.a);
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<line> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].a>>v[i].b;
    }
    sort(v.begin(),v.end(),cmp);

    vector<line> hull;
    for (int i=0;i<n;i++) {
        if (!hull.empty()&&v[i].a==hull.back().a) {
            if (v[i].b > hull.back().b) hull.pop_back(); //b比原本的大 留新的
            else continue;
        }

        while (hull.size()>=2&&is_useless(hull[hull.size()-2],hull.back(),v[i])) {
            hull.pop_back();
        }
        hull.push_back(v[i]);
    }
    long long ans=0;
    for (int i=0;i<m;i++) {
        long long query_x;
        cin>>query_x;

        int l = 0, r = hull.size() - 1;
        long long current_max = -2e18;
        while (l<=r) {
            int mid = (l+r)/2;
            long long value = hull[mid].eval(query_x);
            current_max = max(value,current_max);
            //判斷往上還往下,如果右邊的比較大代表往右會越來越大 左邊的比較小的話代表左邊比較大(斜率為負)
            if (mid + 1 < hull.size() && hull[mid].eval(query_x) < hull[mid+1].eval(query_x)) {
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        ans+=current_max;
    }
    cout << ans;
}