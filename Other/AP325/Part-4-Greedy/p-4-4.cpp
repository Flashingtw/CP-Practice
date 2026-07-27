#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct game {
    int start,finish;
};

bool cmp(game g1 , game g2) {
    return g1.finish<g2.finish;
}

int main() {
    int n;
    cin>>n;
    vector<game> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i].start;
        cin>>v[i].finish;
    }
    sort(v.begin(),v.end(),cmp);
    int count=0,endtime=-1;
    for (int i=0;i<n;i++) {
        if (v[i].start>endtime) {
            count++;
            endtime=v[i].finish;
        }
    }
    cout << count;
}