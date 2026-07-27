#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct tree {
    int pre,next;
    int h;
    int pos;
    int alive = 1;
};

vector<tree> t;
queue<int> q;

void re(int i) {
    if (!t[i].alive) return;
    int pr = t[i].pre,ne=t[i].next;
    if (t[i].pos-t[i].h >= t[pr].pos
        || t[i].pos+t[i].h <=t[ne].pos) {
        t[i].alive = 0;
        q.push(i);
        t[pr].next = ne;
        t[ne].pre = pr;
    }
}

int main() {
    int n,l;
    cin>>n>>l;
    t.resize(n+2);
    t[0].h = 1000000000;
    t[0].pos = 0;
    t[n+1].h = 1000000000;
    t[n+1].pos = l;
    for (int i=1;i<=n;i++) cin>>t[i].pos;
    for (int i=1;i<=n;i++) cin>>t[i].h;
    for (int i=1;i<=n;i++) {
        t[i].pre = i-1;
        t[i].next = i+1;
    }
    for (int i=1;i<=n;i++) {
        re(i);
    }

    int total=0,high=0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        total++;

        high = max(high,t[v].h);

        re(t[v].pre);
        re(t[v].next);
    }
    cout << total << "\n" << high;
}