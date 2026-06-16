#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int a[100];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];//輸入數字資料
    sort(a,a+n);//排序陣列
    int target;
    cin>>target;//輸入目標值
    int l=0,r=n-1;//
    bool ans=0;//紀錄答案用
    while(l<=r){//迴圈啟動!
        int mid = (l+r)/2;//算中點
        if(a[mid]<target){
            l = mid+1;//如果比較小 就縮左界
        }
        else if(a[mid]>target){
            r = mid-1;//如果比較大 就縮右界
        }
        else {
            //找到答案了! 直接break掉迴圈
            ans = 1;
            break;
        }
    }
    cout << ans << '\n';//輸出答案
}
