#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> tp(6,0);//6種 0 是綠豆沙 1-5是紅豆餅
    for (int i=0;i<n;i++) {
        int num;
        cin>>num;
        tp[num]++;
    }
    int total = 0;//紅豆餅數量
    for (int i =1;i<6;i++) total+=tp[i];
    int ans=0;
        //紅豆餅數量>=綠豆沙數量
    if (total-tp[0]>=0)ans+= tp[0]*59 + (total-tp[0])*20;
        //綠豆沙數量比紅豆餅多
    else ans+= total*59 + (tp[0]-total)*50;

    for (int i : tp) cout << i << " ";
    cout << ans;
}