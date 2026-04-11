#include <bits/stdc++.h>
using namespace std;
/*
思考錯誤: 用col繼續搜row而不是1,n
*/
int main(){
    int n;
    cin>>n;
    int l = 1 ,r = n,row=1,col=1;
    while(l<=r){
        int mid = (l+r)/2;
        cout << '?' << 1 << " " << n << " " << l << " " << mid << " " << endl;
        int a;
        cin>>a;
        if(a==mid-l+1){
            l = mid+1;       
        }
        else{
            col=mid;
            r = mid-1;
        }
    }
    l = 1,r = n;
    while(l<=r){
        int mid = (l+r)/2;
        cout << '?' << l << " " << mid << " " << 1 << " " << n << " " << endl;
        int a;
        cin>>a;
        if(a==mid-l+1){
            l = mid+1;       
        }
        else{
            row=mid;
            r = mid-1;
        }
    }
    cout << '!' << row << ' ' << col << endl;
}