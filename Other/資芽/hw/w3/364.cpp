#include <bits/stdc++.h>
using namespace std;
int cnt[1505];
int n;
void initialize(int N){
    n = N;
    memset(cnt, 0, sizeof(cnt));
}
int hasEdge(int a, int b){
    int u = max(a,b);
    cnt[u]++;
    if(cnt[u]==u){
        return 1;
    }
    return 0;
}