#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for (int i=0;i<n;i++) {
        long long a;
        cin>>a;
        v[i] = i==0 ? a : v[i-1]+a;
    }

    long long total_sum = v.back();
    int pos = 0;
    for(int i=0;i<m;i++) {
        long long score;
        cin>>score;
        long long offset = (pos == 0) ? 0 : v[pos - 1];//前一個
        int remainder = total_sum-offset;
        if (score<=remainder) {
            score+=offset;
        }
        else {
            score-=remainder;
            score = (score-1)%total_sum+1;
        }
        auto it = lower_bound(v.begin(),v.end(),score);
        pos = (it-v.begin()+1)%n;
    }
    cout << pos;
}