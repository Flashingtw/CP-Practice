#include <bits/stdc++.h>
using namespace std;
struct point {
    int x,y;
};

bool cmp(point p1, point p2) {
    return p1.x<p2.x;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    vector<point> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].x>>v[i].y;
    }
    sort(v.begin(),v.end(),cmp);
    multimap<int,int> mm;
    int min_d = 2000000001;
    for (int i=0;i<n;i++) {
        auto it = mm.lower_bound(v[i].y-min_d);//過濾 >=y-d
        while (it!=mm.end()&&it->first<=v[i].y+min_d) {//過濾<=y+d
            if (it->second<v[i].x-min_d) {//過濾x
                it = mm.erase(it);
                continue;
            }
            min_d = min(min_d,
                abs(v[i].x-it->second)+abs(v[i].y-it->first));
            it++;
        }
        mm.insert({v[i].y,v[i].x});
    }
    cout << min_d;
}