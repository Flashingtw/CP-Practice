#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(int a, int b) {
    if (a<=b) return b-a; 
    else return -1LL * (a-b) * (a-b);
}
int main(){
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    ll total_sum=0;
    vector<int> cnt(n);
    for(int i=0;i<n-1;i++){
        if(v[i]<=v[i+1]) total_sum+=v[i+1]-v[i];
        else total_sum-= 1LL*(v[i]-v[i+1])*(v[i]-v[i+1]);
    }
    ll _max=total_sum;
    for(int i=0; i<n; i++){
        int L = (i == 0) ? -1:v[i-1];
        int R = (i == n-1) ? -1:v[i+1];

        ll old_score = 0;
        if (L != -1) old_score += cal(L, v[i]);
        if (R != -1) old_score += cal(v[i], R);

        vector<int> res;
        res.push_back(0);
        res.push_back(c);
        if (L != -1) res.push_back(L);
        if (R != -1) res.push_back(R);   
        if (L != -1 && R != -1) res.push_back((L+R)/2);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        for (int x:res) {
            ll new_score = 0;
            if (L!=-1) new_score += cal(L,x);
            if (R!=-1) new_score += cal(x,R);
            _max = max(_max,total_sum-old_score+new_score);
        }
    }
    cout << _max;
}